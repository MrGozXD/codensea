import java.util.concurrent.TimeUnit;

/**
 * demoStudents
 */
public class demoStudents {

    public static void main(String[] args) {
        Integer a = Integer.parseInt(args[0]);
        Student[] list = new Student [a];

        for (int x = 0; x < 10; x++) {
            list[x]=new Student("Antoine","Tauvel");

        }

    

        System.out.println("Actual number of Students: " + list[0].getTotalNumberOfStudents());
        list[1]=list[0];
        System.gc();
        try{TimeUnit.SECONDS.sleep(10);}
        catch(Exception e){
            System.out.println("Won\'t go to sleep !");
        }
        System.out.println("Actual number of Students : "+list[0].getTotalNumberOfStudents());
    }
}
