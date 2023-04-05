//IMT2021078
import java.util.*;
import java.io.*;

public class Spinner extends Car
{
    private int initx,inity,finalx,finaly,limit,steps;
    private String initdir, resultStr;

    public Spinner(int posX,int posY,String dir,int leftNum,int rightNum,int topNum,int bottomNum)
    {
        super(leftNum,rightNum,topNum,bottomNum);
        initx=posX;
        inity=posY;
        initdir=dir;
    }

    public String move(int K, int N)
    {
        steps=K*N;

        //maintaining lists where the directions are all in cyclic order(if car is moving right, it hits the wall and goes down and then if it hits the bottom bound, it goes left and so on)
        ArrayList<String> rList=new ArrayList<String>(Arrays.asList("right","down","left","up"));
        ArrayList<String> lList=new ArrayList<String>(Arrays.asList("left","up","right","down"));
        ArrayList<String> tList=new ArrayList<String>(Arrays.asList("up","right","down","left"));
        ArrayList<String> bList=new ArrayList<String>(Arrays.asList("down","left","up","right"));
        ArrayList<String> dirList2=new ArrayList<>();
        
                if(initdir.equals("right"))
                    dirList2=rList;
                else if(initdir.equals("down"))
                    dirList2=bList;
                else if(initdir.equals("left"))
                    dirList2=lList;
                else if(initdir.equals("up"))
                    dirList2=tList;
            

        finalx=initx;
        finaly=inity;

        for(int iSpin=0;iSpin<4;iSpin++)
        {
            
                if(dirList2.get(iSpin).equals("left"))
                {

                    limit=finalx-leftNum;
                    if(steps<=limit)
                    {
                        //finaly has previous y coordinate already
                        finalx=finalx-steps;
                        resultStr=finalx+" "+finaly+"\n";
                        return(resultStr);

                    }
                    else
                    {
                        finalx=leftNum; //if number of steps remaining are more than the limit, we move the car till the bound of the grid in that direction first and then continue the iteration. in the next iteration, the direction changes as per the direction elements in the list above
                        //finaly=inity; is already the assigned value of finaly
                        steps=steps-limit;
                    }
                }
                else if(dirList2.get(iSpin).equals("up"))
                {
                    limit=finaly-topNum;
                    if(steps<=limit)
                    {
                        finaly=finaly-steps;
                        resultStr=finalx+" "+finaly+"\n";
                        return(resultStr);
                    }
                    else
                    {
                        finaly=topNum;
                        steps=steps-limit;
                    }
                }
                else if(dirList2.get(iSpin).equals("right"))
                {
                    limit=rightNum-finalx;
                    if(steps<=limit)
                    {
                        finalx=finalx+steps;
                        resultStr=finalx+" "+finaly+"\n";
                        return(resultStr);
                    }
                    else
                    {
                        finalx=rightNum;
                        steps=steps-limit;
                    }
                }
                else if(dirList2.get(iSpin).equals("down"))
                {
                    limit=bottomNum-finaly;
                    if(steps<=limit)
                    {
                        finaly=finaly+steps;
                        resultStr=finalx+" "+finaly+"\n";
                        return(resultStr);
                    }
                    else
                    {
                        finaly=bottomNum;
                        steps=steps-limit;
                    }
                }

                if(iSpin==3)
                    iSpin=0;
            
            

        }
        return null;
    }
}