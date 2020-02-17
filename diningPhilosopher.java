
// java program to demonstrate  
// use of semaphores Locks 
import java.util.concurrent.*; 
  
//A shared resource/class. 
class Shared  
{ 
    static int count[] = new int[5]; 
} 
  
class MyThread extends Thread 
{ 
    Semaphore sem; 
    String threadName; 
    public MyThread(Semaphore sem, String threadName)  
    { 
        super(threadName); 
        this.sem = sem; 
        this.threadName = threadName; 
    } 
    public void eat(){
        //System.out.println("Starting " + threadName); 
            try 
            { 
                System.out.println(" Philosopher "+ threadName + " is thinking...."); 
              
                // acquiring the semaphore 
                sem.acquire(); 
              
                System.out.println(" Philosopher "+ threadName + " gets a fork."); 
                
                //int index = Integer.parseInt(threadName);

                //Shared.count[index] += 1;
                //System.out.println(Shared.count[index]);

                //if(Shared.count[index] == 2){
                System.out.println(" Philsopher " + threadName + " starts eating.");
                Thread.sleep(2000);
                System.out.println(" Philsopher " + threadName + " stops eating.");
                //Shared.count[index] = 0;
                sem.release();

                //}
            } catch (InterruptedException exc) { 
                    System.out.println(exc); 
            } 
    }
  
    public void run() {
        int x = 5;
        while(x-- >0){
            eat();
        }
    }
}
  
// Driver class 
public class diningPhilosopher 
{ 
    public static void main(String args[]) throws InterruptedException  
    { 
        // creating a Semaphore object 
        // with number of 3 pair of forks
        Semaphore sem = new Semaphore(3, true); 
        
        //creating 5 philosopher
        MyThread mt0 = new MyThread(sem, "A"); 
        MyThread mt1 = new MyThread(sem, "B"); 
        MyThread mt2 = new MyThread(sem, "C"); 
        MyThread mt3 = new MyThread(sem, "D"); 
        MyThread mt4 = new MyThread(sem, "E"); 
          
        // starting threads.
        //for(int i=0; i<20; i++){
            mt0.start(); 
            mt1.start(); 
            mt2.start(); 
            mt3.start(); 
            mt4.start(); 
        //}
        //waiting for semaphore
        //for(int i=0; i<20; i++){
            mt0.join(); 
            mt1.join(); 
            mt2.join(); 
            mt3.join(); 
            mt4.join(); 
       // }
    } 
}