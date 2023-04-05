//IMT2021078
import java.util.*;
import java.io.*;

public class PingPong extends Car
{
    private int initx,inity,finalx,finaly,limit,steps;
    private String initdir, resultStr;

    public PingPong(int posX,int posY,String dir,int leftNum,int rightNum,int topNum,int bottomNum)
    {
        super(leftNum,rightNum,topNum,bottomNum);
        initx=posX;
        inity=posY;
        initdir=dir;
    }

    public String move(int K, int N)
    {
        steps=K*N;
        finalx=initx; //finalx and finaly refer to the coordinates after a certain movement
        finaly=inity;
        while(steps>0)
        {
                if(initdir.equals("left"))
                {

                    limit=finalx-leftNum;
                    if(steps<=limit) //same logic as Lemon
                    {
                        //finaly has previous y coordinate already
                        finalx=finalx-steps;
                        resultStr=finalx+" "+finaly+"\n";
                        return(resultStr);

                    }
                    else
                    {
                        finalx=leftNum;
                        //finaly=inity; is already the assigned value of finaly
                        steps=steps-limit; //removing the steps covered till we reach the wall
                        initdir="right"; //once it hits the wall, we rebound, i. e., if the current dir is left it becomes right and vice versa
                    }
                }
                else if(initdir.equals("up"))
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
                        initdir="down";
                    }
                }
                else if(initdir.equals("right"))
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
                        initdir="left";
                    }
                }
                else if(initdir.equals("down"))
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
                        initdir="up";
                    }
                }
        }
        return null;
       
    }
}