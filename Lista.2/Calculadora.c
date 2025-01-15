#ifndef CALCULADORA_H_INCLUDED
#define CALCULADORA_H_INCLUDED

void soma(){
float Valor1, Valor2, resultado;
printf("\nDigite o primeiro Valor:");
scanf("%f", &Valor1);
printf("\nDigite o segundo Valor:");
scanf("%f", &Valor2);
resultado = Valor1 + Valor2;
printf("\nO resultado e: %.2f\n\n", resultado);
menu();
system ("pause");
system("cls");

}
void subtracao(){
float Valor1, Valor2, resultado;
printf("\nDigite o primeiro Valor:");
scanf("%f", &Valor1);
printf("\nDigite o segundo Valor:");
scanf("%f", &Valor2);
resultado = Valor1 - Valor2;
printf("\nO resultado e: %2f\n\n", resultado);
menu();
system ("pause");
system("cls");
}
void multiplicacao(){
float Valor1, Valor2, resultado;
printf("\nDigite o primeiro Valor:");
scanf("%f", &Valor1);
printf("\nDigite o segundo Valor:");
scanf("%f", &Valor2);
resultado = Valor1 * Valor2;
printf("\nO resultado e: %.2f\n\n", resultado);
menu();
system ("pause");
system("cls");
}

void divisao(){
float Valor1, Valor2, resultado;
printf("\nDigite o primeiro Valor:");
scanf("%f", &Valor1);
printf("\nDigite o segundo Valor:");
scanf("%f", &Valor2);
resultado = Valor1 / Valor2;
printf("\nO resultado e: %.2f\n\n", resultado);
menu();
system ("pause");
system("cls");
}

void menu(){
int escolha;

printf("\n<<<<<<<<<<<<<<< Menu >>>>>>>>>>>>>>>\n");

printf("\nEscolha uma operacao matematica:");
printf("\n1.Adicao");
printf("\n2.Subtracao");
printf("\n3.Multiplicacao");
printf("\n4.Divisao");
printf("\n5.Sair\n\n");
scanf("%d", &escolha);

switch(escolha){
case 1:
soma();
break;
case 2:
subtracao();
break;
case 3:
multiplicacao();
break;
case 4:
divisao();
break;
case 5:
system("exit");
printf("Fim do programa!\n\n");
system ("pause");
system("cls");

}
}

#endif