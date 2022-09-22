char * removeOuterParentheses(char * s){
    int count = 0;
    int slen = strlen(s);
    char *ans = (char*)malloc(slen * sizeof(ans));
    strcpy(ans,"");
    
    for(int i = 0; i < slen; i++){
        if(count == 0 && s[i] == '('){
            count++;
        }else if(count > 0 && s[i] == '('){
            strcat(ans, "(");
            count++;
        }else if(count > 1 && s[i] == ')'){
            strcat(ans, ")");
            count--;
        }else{
            count--;
        }
    }
    
    printf("%s", ans);

    return ans;
}
