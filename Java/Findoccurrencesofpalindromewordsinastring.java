import java.util.*;
class Main
{
  static boolean checkPalin(String word)
      {
          int n = word.length();
          word = word.toLowerCase();
          for (int i=0; i<n; i++,n--)
             if (word.charAt(i) != word.charAt(n - 1))
                return false;
          return true;
      }
  static int countPalindrome(String str)
  {
   str = str + " ";


          String word = "";
          int count = 0;
          for (int i = 0; i < str.length(); i++)
          {
              char ch = str.charAt(i);


              if (ch != ' ')
                  word = word + ch;
              else {
                  if (checkPalin(word))
                      count++;
                  word = "";
              }
          }

          return count;
  }
public static void main(String[] args)
{
  int j=0;
  String a;
  Scanner s=new Scanner(System.in);
  a = s.nextLine().trim();
  j=countPalindrome(a);
  System.out.println(j);
}
}
