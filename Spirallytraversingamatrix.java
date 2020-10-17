import java.util.Scanner;

class Result
{
  static void printSpiral(int a[][], int r, int c)
  {
    int i,k=0,l=0; //m=r,n=c
    while(k<r && l<c){
      for(i=l;i<c;i++)
        System.out.println(a[k][i]);
      k++;
      for(i=k;i<r;i++)
        System.out.println(a[i][c-1]);
      c--;
        if(k<r){
          for(i=c-1;i>=l;i--)
            System.out.println(a[r-1][i]);
      r--;}
      if(l<c){
        for(i=r-1;i>=k;i--)
          System.out.println(a[i][l]);
        l++;
      }
    }
  }
}

class Main
{
  public static void main(String[] args)
  {
    int r, c, i, j;
    Scanner sc = new Scanner(System.in);
    r = sc.nextInt();
    c = sc.nextInt();
    int a[][] = new int[50][50];
    for(i = 0; i < r; i++)
      for(j = 0; j < c; j++)
        a[i][j] = sc.nextInt();
    Result.printSpiral(a, r, c);
  }
}
