/*
Artur Rodrigues Santos

Lista II - Questão 05

Crie um programa qual entre com argumentos e desenvolva funções que:

a) Calcule o valor líquido do salário à ser recebido por um colaborador;

b) Calcule o valor total do salário à ser pago a um colaborador, por parte da empresa;
*/

#include <stdio.h>
#include <stdlib.h>

float calculo(int faixa,float salario);

int main(int argc, char *argv[]) {

	float salario = atof(argv[1]);
	float hr_semanal = atof(argv[2]);
	float hr_extra = atof(argv[3]);
	float hr_atraso = atof(argv[4]);
	float valetrans = atof(argv[5]);
	float plasaude = atof(argv[6]);
	float valerefei = atof(argv[7]);

	float porcentagem = 0;
	float taxa = 0,taxa_2 = 0,taxa_3 = 0,taxa_4 = 0;
	float liquido = 0;
	float faixa = 0,faixa_2 = 0,faixa_3 = 0,faixa_4 = 0;
	float inss = 0,inss_2 = 0,inss_3 = 0,inss_4 = 0;
	float salario_hora = 0,salario_extra = 0,salario_atrasos = 0;
	float desct = 0;
	float imposto = 0;
	float debito = 0;

	printf("Olá, veja aqui qual o valor você pagará de \x1b[1mImposto de Renda.\x1b[0m\n\nPrimeiramente, veja aqui a tabela de porcentagem:\n\n\nAté 2259,20R$ - \x1b[32m\x1b[1mIsento :)\x1b[0m\n---------------------------------------------------\nDe 2259,21R$ até 2826,65R$ - \x1b[31m\x1b[1m7,5 porcento de taxa\x1b[0m\n---------------------------------------------------\nDe 2826,66R$ até 3751,05R$ - \x1b[31m\x1b[1m15 porcento de taxa\x1b[0m\n---------------------------------------------------\nDe 3751,06R$ até 4664,68R$ - \x1b[31m\x1b[1m22,5 porcento de taxa\x1b[0m\n---------------------------------------------------\nAcima de 4664,68R$ - \x1b[31m\x1b[1m27,5 porcento de taxa\x1b[0m\n---------------------------------------------------\n\n");

	porcentagem = (salario < 1412) ? printf("Você está recebendo menos do que um salário minimo, recomendamos procurar a justiça. Dito isso, você está isento de imposto") : 0;
	porcentagem = (1412 < salario && salario <= 2259.20) ? printf("\nvocê está isento de taxas do imposto de renda, pois seu salário é menor do que 2259,21R$\n") : 0;
	porcentagem = 0;
	porcentagem = (2259.20 < salario && salario <= 2826.65) ? 1 : porcentagem;
	porcentagem = (2826.65 < salario && salario <= 3751.05) ? 2 : porcentagem;
	porcentagem = (3751.05 < salario && salario <= 4664.68) ? 3 : porcentagem;
	porcentagem = (salario > 4664.68) ? 4 : porcentagem;

	imposto = (salario < 1412.01) ? 1 : imposto;
	imposto = (salario > 1412 && salario < 2666.69) ? 2 : imposto;
	imposto = (salario > 2666.68 && salario < 4000.04) ? 3 : imposto;
	imposto = (salario > 4000.03 && salario < 7786.03) ? 4 : imposto;
	imposto = (salario > 7786.02) ? 5 : imposto;

	if(imposto >= 1) {
		inss = salario*0.075;
	}
	if(imposto >1) {
		inss = 1412*0.075;
		inss_2 = (salario - 1412)*0.09;
	}

	imposto = calculo(imposto,salario);

	salario_hora = salario / (hr_semanal*5);
	salario_extra = (salario_hora*1.5)*hr_extra;
	salario_atrasos = salario_hora*hr_atraso;

	printf("\n---------------------------------------------------\nGanhos com horas extras: R$ %2.f",salario_extra);
	printf("\n---------------------------------------------------\nDescontos de atrasos: R$ %.2f",salario_atrasos);
	printf("\n---------------------------------------------------\n\x1b[36mSeu salário-hora é de R$%.2f e a sua hora extra vale R$%.2f\x1b[0m\n\n",salario_hora,salario_hora*1.5);

	desct = valetrans*0.06+valerefei+salario_extra+plasaude*0.20;



    if(porcentagem == 0) {
		liquido = salario - inss - inss_2;
    }

    if(porcentagem >= 1) {
		taxa = (salario - 2259.20)*0.075;
		faixa = taxa;
		liquido = salario - taxa;
    }

	if ( porcentagem > 1 ) {
		taxa = (2826.65 - 2259.20)*0.075;
		taxa_2 = taxa +(salario - 2826.65)*0.15;
		faixa = taxa;
		faixa_2 = taxa_2 - taxa;
		liquido = salario - taxa_2;
    }

	if ( porcentagem > 2 ) {
		taxa_2 = taxa +(3751.05 - 2826.65)*0.15;
		taxa_3 = taxa_2 + (salario - 3751.05)*0.225;
		faixa_2 = taxa_2 - taxa;
		faixa_3 = taxa_3 - taxa_2;
		liquido = salario - taxa_3;
	}

	if ( porcentagem > 3 ) {
		taxa_3 = taxa_2 + (4664.68 - 3751.05)*0.225;
		taxa_4 = taxa_3 + (salario - 4664.68)*0.275;
		faixa_3 = taxa_3 - taxa_2;
		faixa_4 = taxa_4 - taxa_3;
		liquido = salario - faixa_4;
	}

	imposto = imposto + faixa + faixa_2 + faixa_3 + faixa_4;

	debito = imposto + salario_atrasos;

	liquido = salario - debito + desct;

	if(salario > 2259.20 && salario <= 2826.65){
	printf("\nVocê será taxado em:\n\nImposto de Renda\n---------------------------------------------------\nDe 2259,21R$ até 2826,65R$ - \x1b[1m7,5 porcento de taxa | \x1b[31m%.2fR$\x1b[0m\n---------------------------------------------------\nDe 2826,66R$ até 3751,05R$ - \x1b[1m15 porcento de taxa  | \x1b[32mIsento\x1b[0m\n---------------------------------------------------\nDe 3751,06R$ até 4664,68R$ - \x1b[1m22,5 porcento de taxa| \x1b[32mIsento\x1b[0m\n---------------------------------------------------\nAcima de 4664,68R$ - \x1b[1m27,5 porcento de taxa        | \x1b[32mIsento\x1b[0m\n---------------------------------------------------\n\n",faixa);
	}  else if(salario > 2826.65 && salario <= 3751.05) {
	printf("\nVocê será taxado em:\n\nImposto de Renda\n---------------------------------------------------\nDe 2259,21R$ até 2826,65R$ - \x1b[1m7,5 porcento de taxa | \x1b[31m%.2fR$\x1b[0m\n---------------------------------------------------\nDe 2826,66R$ até 3751,05R$ - \x1b[1m15 porcento de taxa  | \x1b[31m%.2fR$\x1b[0m\n---------------------------------------------------\nDe 3751,06R$ até 4664,68R$ - \x1b[1m22,5 porcento de taxa| \x1b[32mIsento\x1b[0m\n---------------------------------------------------\nAcima de 4664,68R$ - \x1b[1m27,5 porcento de taxa        | \x1b[32mIsento\x1b[0m\n---------------------------------------------------\n\n",faixa,faixa_2);
	} else if(salario > 3751.05 && salario <= 4664.68) {
	printf("\nVocê será taxado em:\n\nImposto de Renda\n---------------------------------------------------\nDe 2259,21R$ até 2826,65R$ - \x1b[1m7,5 porcento de taxa | \x1b[31m%.2fR$\x1b[0m\n---------------------------------------------------\nDe 2826,66R$ até 3751,05R$ - \x1b[1m15 porcento de taxa  | \x1b[31m%.2fR$\x1b[0m\n---------------------------------------------------\nDe 3751,06R$ até 4664,68R$ - \x1b[1m22,5 porcento de taxa| \x1b[31m%.2fR$\x1b[0m\n---------------------------------------------------\nAcima de 4664,68R$ - \x1b[1m27,5 porcento de taxa        | \x1b[32mIsento\x1b[0m\n---------------------------------------------------\n\n",faixa,faixa_2,faixa_3);
	}
	else if(salario > 4664.68) {
		printf("\nVocê será taxado em:\n\nImposto de Renda\n---------------------------------------------------\nDe 2259,21R$ até 2826,65R$ - \x1b[1m7,5 porcento de taxa | \x1b[31m%.2fR$\x1b[0m\n---------------------------------------------------\nDe 2826,66R$ até 3751,05R$ - \x1b[1m15 porcento de taxa  | \x1b[31m%.2fR$\x1b[0m\n---------------------------------------------------\nDe 3751,06R$ até 4664,68R$ - \x1b[1m22,5 porcento de taxa| \x1b[31m%.2fR$\x1b[0m\n---------------------------------------------------\nAcima de 4664,68R$ - \x1b[1m27,5 porcento de taxa        | \x1b[31m%.2fR$\x1b[0m\n---------------------------------------------------\n",faixa,faixa_2,faixa_3,faixa_4);
	}

	if(salario<1412.01) {
		printf("\nINSS\n---------------------------------------------------\nAté 1412.00 - \x1b[1m7,5 porcento de taxa                | \x1b[31m%.2fR$\x1b[0m\n---------------------------------------------------\nDe 1412.01R$ até 2666.68R$ - \x1b[1m9 porcento de taxa   | \x1b[32mIsento\x1b[0m\n---------------------------------------------------\nDe 2666.69R$ até 4000.03R$ - \x1b[1m12 porcento de taxa  | \x1b[32mIsento\x1b[0m\n---------------------------------------------------\nDe 4000.04R$ até 7786.02R$ - \x1b[1m14 porcento de taxa  | \x1b[32mIsento\x1b[0m\n---------------------------------------------------\n\nSerá cobrado aproximadamente \x1b[31m%.2fR$\x1b[0m e creditado aproxidamente \x1b[32m%.2fR$.\x1b[0m do seu salário (%.2fR$).Seu salário liquído é de \x1b[32m%.2fR$.\x1b[0m",inss,debito,desct,salario,liquido);
	} else if (salario > 1412 && salario < 2666.69) {
		printf("\nINSS\n---------------------------------------------------\nAté 1412.00 - \x1b[1m7,5 porcento de taxa                | \x1b[31m%.2fR$\x1b[0m\n---------------------------------------------------\nDe 1412.01R$ até 2666.68R$ - \x1b[1m9 porcento de taxa   | \x1b[31m%.2fR$\x1b[0m\n---------------------------------------------------\nDe 2666.69R$ até 4000.03R$ - \x1b[1m12 porcento de taxa  | \x1b[32mIsento\x1b[0m\n---------------------------------------------------\nDe 4000.04R$ até 7786.02R$ - \x1b[1m14 porcento de taxa  | \x1b[32mIsento\x1b[0m\n---------------------------------------------------\n\nSerá cobrado aproximadamente \x1b[31m%.2fR$\x1b[0m e creditado aproxidamente \x1b[32m%.2fR$.\x1b[0m do seu salário (%.2fR$).Seu salário liquído é de \x1b[32m%.2fR$.\x1b[0m",inss,inss_2,debito,desct,salario,liquido);
    }
	else if (salario > 2666.68 && salario < 4000.04) {
		printf("\nINSS\n---------------------------------------------------\nAté 1412.00 - \x1b[1m7,5 porcento de taxa                | \x1b[31m%.2fR$\x1b[0m\n---------------------------------------------------\nDe 1412.01R$ até 2666.68R$ - \x1b[1m9 porcento de taxa   | \x1b[31m%.2fR$\x1b[0m\n---------------------------------------------------\nDe 2666.69R$ até 4000.03R$ - \x1b[1m12 porcento de taxa  | \x1b[31m%.2fR$\x1b[0m\n---------------------------------------------------\nDe 4000.04R$ até 7786.02R$ - \x1b[1m14 porcento de taxa  | \x1b[32mIsento\x1b[0m\n---------------------------------------------------\n\nSerá cobrado aproximadamente \x1b[31m%.2fR$\x1b[0m e creditado aproxidamente \x1b[32m%.2fR$.\x1b[0m do seu salário (%.2fR$).Seu salário liquído é de \x1b[32m%.2fR$.\x1b[0m",inss,inss_2,inss_3,debito,desct,salario,liquido);
  	}
  	else if (salario > 4000.03 && salario < 7786.03) {
		printf("\nINSS\n---------------------------------------------------\nAté 1412.00 - \x1b[1m7,5 porcento de taxa                | \x1b[31m%.2fR$\x1b[0m\n---------------------------------------------------\nDe 1412.01R$ até 2666.68R$ - \x1b[1m9 porcento de taxa   | \x1b[31m%.2fR$\x1b[0m\n---------------------------------------------------\nDe 2666.69R$ até 4000.03R$ - \x1b[1m12 porcento de taxa  | \x1b[31m%.2fR$\x1b[0m\n---------------------------------------------------\nDe 4000.04R$ até 7786.02R$ - \x1b[1m14 porcento de taxa  | \x1b[31m%.2fR$\x1b[0m\n---------------------------------------------------\n\nSerá cobrado aproximadamente \x1b[31m%.2fR$\x1b[0m e creditado aproxidamente \x1b[32m%.2fR$.\x1b[0m do seu salário (%.2fR$).Seu salário liquído é de \x1b[32m%.2fR$.\x1b[0m",inss,inss_2,inss_3,inss_4,debito,desct,salario,liquido);
 	}
 	else if (salario > 7786.02) {
		printf("\nINSS\n---------------------------------------------------\nAté 1412.00 - \x1b[1m7,5 porcento de taxa                | \x1b[31m%.2fR$\x1b[0m\n---------------------------------------------------\nDe 1412.01R$ até 2666.68R$ - \x1b[1m9 porcento de taxa   | \x1b[31m%.2fR$\x1b[0m\n---------------------------------------------------\nDe 2666.69R$ até 4000.03R$ - \x1b[1m12 porcento de taxa  | \x1b[31m%.2fR$\x1b[0m\n---------------------------------------------------\nDe 4000.04R$ até 7786.02R$ - \x1b[1m14 porcento de taxa  | \x1b[31m%.2fR$\x1b[0m\n---------------------------------------------------\n\nSerá cobrado aproximadamente \x1b[31m%.2fR$\x1b[0m e creditado aproxidamente \x1b[32m%.2fR$.\x1b[0m do seu salário (%.2fR$).Seu salário liquído é de \x1b[32m%.2fR$.\x1b[0m",inss,inss_2,inss_3,inss_4,debito,desct,salario,liquido);
  	}
	printf("\n\n\n\x1b[1mVamos dar uma olhada em outros gastos que sua empresa tem com você além do seu salário bruto e qual o custo de um funcionário por mês.\x1b[0m\n");

	float Gastos_empresa = salario * 0.11 + salario * 0.0833 + salario * 0.08 + salario * 0.04 + salario * 0.0793 + valerefei + valetrans * 0.06 + plasaude * 0.8;

	printf("\n\n\x1b[36m\x1b[1mGastos da Empresa\x1b[0m\n---------------------------------------------------\nFração de férias                     | R$ %.2f\n---------------------------------------------------\nFração do 13º salário                | R$ %.2f\n---------------------------------------------------\nFGTS                                 | R$ %.2f\n---------------------------------------------------\nPrevisão de multa para recisão       | R$ %.2f\n---------------------------------------------------\nPrevidenciário                       | R$ %.2f\n---------------------------------------------------\nVale transporte                      | R$ %.2f\n---------------------------------------------------\nVale Alimentação                     | R$ %.2f\n---------------------------------------------------\nPlano de Saúde                       | R$ %.2f\n---------------------------------------------------\nTotal de Gastos                      | R$ %.2f\n---------------------------------------------------\n\n",salario*0.11,salario*0.0833,salario*0.08,salario*0.04,salario*0.0793,valetrans,valerefei,plasaude,Gastos_empresa);

	printf("\x1b[36m\x1b[1mSeu custo para empresa é de R$ %.2f\x1b[0m",salario+Gastos_empresa);

	printf("\n\n(Isso representa um valor \x1b[32m\x1b[1m %.2f%% \x1b[0m maior em relação ao salário bruto).", (Gastos_empresa+ salario) / salario * 100);

	return 0;
}

float calculo(int faixa,float salario) {

	float inss = 0,inss_2 = 0,inss_3 = 0,inss_4 = 0;

	if(faixa >= 1) {
		inss = salario*0.075;
	}
	if(faixa >1) {
		inss = 1412*0.075;
		inss_2 = (salario - 1412)*0.09;
	}
	if(faixa >2) {
		  inss_2 = 112.92;
		  inss_3 = (salario - 2666.68)*0.12;
	}
	if(faixa > 3) {
		  inss_3 = 160;
		  inss_4 = (salario - 4000.03)*0.14;
	}
	if(faixa > 4) {
		  inss_4 = (7786.02 - 4000.03)*0.14;
	}

	return inss + inss_2 + inss_3 + inss_4;
}
