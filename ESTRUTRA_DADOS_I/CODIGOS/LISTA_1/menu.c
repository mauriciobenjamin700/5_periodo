int menu(void){
    char escolha;
    printf("\n1 - Iniciar o programa\n2 - Encerrar o programa\n\nSua escolha: ");
    scanf("%c", &escolha);

    if (escolha == '1'){
        return '1';
    }
    else if (escolha=='2'){
        return '2';
    }
    else{
        return '0';
    }
}