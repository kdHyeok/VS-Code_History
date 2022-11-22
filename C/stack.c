void hanoi(int x, char a, char b, char c){
    if (x==1){
        printf("원판 1을 %c에서 %c로 옮긴다\n",a,c);
    }
    else{
        hanoi(x-1, a, c, b);
        printf("원판 %d을 %c에서 %c로 옮긴다\n",x,a,c);
        hanoi(x-1, b, a, c);
    }

}

void main(){
    hanoi(4, 'A', 'B', 'C');
}