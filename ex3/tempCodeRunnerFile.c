
    int new_process = fork();
    if (new_process){
        printf("%s from child\n", hello);
    }