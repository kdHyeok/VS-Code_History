void hanoi(int x, char a, char b, char c){
    if (x==1){
        printf("���� 1�� %c���� %c�� �ű��\n",a,c);
    }
    else{
        hanoi(x-1, a, c, b);
        printf("���� %d�� %c���� %c�� �ű��\n",x,a,c);
        hanoi(x-1, b, a, c);
    }

}

void main(){
    hanoi(4, 'A', 'B', 'C');
}