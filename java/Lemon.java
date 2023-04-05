//IMT2021078
import java.util.*;
import java.io.*;

public class Lemon extends Car
{
    private int initx,inity,finalx,finaly,llimit,rlimit,tlimit,blimit,steps;
    private String initdir,resultStr;

    public Lemon(int posX,int posY,String dir,int leftNum,int rightNum,int topNum,int bottomNum)
    {
        super(leftNum,rightNum,topNum,bottomNum);
        initx=posX;
        inity=posY;
        initdir=dir;
    }

    public String move(int K, int N)
    {
        steps=K*N;

        if(initdir.equals("left"))
        {
            llimit=initx-leftNum; //distance between the left bound of the grid and the current position
            if(llimit<steps)
            {
                finalx=leftNum; //if the remaining steps are more than the limit, we just take the bound of the grid as final position as the car stops upon hitting a wall
            }

            else
            {
                finalx=initx-steps; //if the number of steps remaining are less than the limit, we just add/subtract those steps from the current position depending upon the direction
            }

            finaly=inity; //y-coordinate remains same in left/right movement
            resultStr=finalx+" "+finaly+"\n";
            return(resultStr);
        }

        if(initdir.equals("right"))
        {
            rlimit=rightNum-initx;
            if(rlimit<steps)
            {
                finalx=rightNum;
            }

            else
            {
                finalx=initx+steps;
            }

            finaly=inity;
            resultStr=finalx+" "+finaly+"\n";
            return(resultStr);
        }

        if(initdir.equals("up"))
        {
            tlimit=inity-topNum;
            if(tlimit<steps)
            {
                finaly=topNum;
            }

            else
            {
                finaly=inity-steps;
            }

            finalx=initx;
            resultStr=finalx+" "+finaly+"\n";
            return(resultStr);
        }

        if(initdir.equals("down"))
        {
            blimit=bottomNum-inity;
            if(blimit<steps)
            {
                finaly=bottomNum;
            }

            else
            {
                finaly=inity+steps;
            }

            finalx=initx;
            resultStr=finalx+" "+finaly+"\n";
            return(resultStr);
        }
        return null;
    }
}