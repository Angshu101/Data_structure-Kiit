//import java.util.*;
//import java.io.*;
public class test{
public static void main(String[] args) {
    // Scanner sc =new Scanner(System.in);
    int i,max,rep=0,occ=0;
    //System.out.println("Enter the size of the dynamic array");
     //n=sc.nextInt();
    int arr[]={2,3,5,9,9,9,9};
    // arr=new int[n];
    //  for(i=0;i<n;i++)
    //  {
    //      arr[i]=sc.nextInt();
    //   }
    max=0;
   for(i=0;i<7;i++)
   {
       if(max<arr[i])
         {
          occ=0;
         max=arr[i];
         rep=max;
         }
       if(rep==arr[i])
        occ++;
    }
    System.out.println("The largest number is "+max);
    System.out.println("The number of occurence is"+occ);
    
    
 }
 
}
    
