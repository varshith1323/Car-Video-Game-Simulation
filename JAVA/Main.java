//IMT2021078
import java.util.*;
import java.io.*;

public class Main
{
    public static void main(String[] args)
    {
        Scanner myScan=new Scanner(System.in);

        String bounds=myScan.nextLine();

        String boundsArr[]=bounds.split(" ");
        //store the gird bounds in separate variables
        int l=Integer.parseInt(boundsArr[0]);
        int r=Integer.parseInt(boundsArr[1]);
        int t=Integer.parseInt(boundsArr[2]);
        int b=Integer.parseInt(boundsArr[3]);

        String numCarsStr=myScan.nextLine();
        int numCars=Integer.parseInt(numCarsStr);
        Game gameObj=new Game(l,r,t,b,numCars);

        String carInfo,dir,carType;
        int posX,posY;
        String carInfoArr[];
        for(int i=1;i<=numCars+1;i++)
        {
            if(i==1)
                continue; //to exclude running an empty string in the loop

            carInfo=myScan.nextLine();
            carInfoArr=carInfo.split(" ");
            
            carType=carInfoArr[0];
            posX=Integer.parseInt(carInfoArr[1]);

            posY=Integer.parseInt(carInfoArr[2]);
            dir=carInfoArr[3];

            if(carType.equals("Lemon"))
            {
                //creating respective object using polymorphism and calling addCar method of Game class' object
                Car carObj=new Lemon(posX,posY,dir,l,r,t,b);
                gameObj.addCar(carObj);
            }
            if(carType.equals("PingPong"))
            {
                Car carObj=new PingPong(posX,posY,dir,l,r,t,b);
                gameObj.addCar(carObj);
            }
            if(carType.equals("Spinner"))
            {
                Car carObj=new Spinner(posX,posY,dir,l,r,t,b);
                gameObj.addCar(carObj);
            }


        }

        String numTemp=myScan.nextLine();
        String numTempArr[]=numTemp.split(" ");
        int K=Integer.parseInt(numTempArr[0]);
        int N=Integer.parseInt(numTempArr[1]);     

        System.out.println(gameObj.advance(K,N));
    }
} 