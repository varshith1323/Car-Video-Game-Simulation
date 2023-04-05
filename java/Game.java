//IMT2021078
import java.util.*;
import java.io.*;

public class Game
{
    private List<Car> carsList=new ArrayList<>();
    private int left, right, up, down, numOfCars;

    //constructor
    public Game(int l,int r,int t,int b,int numCars)
    {
        left=l;
        right=r;
        up=t;
        down=b;
        numOfCars=numCars;
    }

    public void addCar(Car carObj)
    {
        carsList.add(carObj);
    }

    public String advance(int stepsK, int timesN)
    {
        String finalResult="";
        for(Car car : carsList) //iterating through the list of objects
        {
            finalResult=finalResult+car.move(stepsK,timesN); //maintaining a string of the result 
        }
        finalResult=finalResult.strip(); //to remove trailing spaces 
        return finalResult;
    }
}

 