import java.util.regex.Pattern;


public class StudentGroup{
    private String name;
    private static int numberOfGroup=0;
    //boolean b = Pattern.matches("[1-2]G[1-3]", name);
    public StudentGroup(String name) throws Exception{
        this.name=name;
        StudentGroup.numberOfGroup++;
        if(!Pattern.matches("[1-2]G[1-3]TD[1-3]TP[1-6]", name))
        {throw new Exception(name+" is not a real ENSEA name");}
    }

    @Override
    public String toString(){
        return this.name;
    }
    
    public static void main(String[] args) {
        StudentGroup a=null,b=null,c=null;
        try{a=new StudentGroup("1G1TD1TP1");
            b=new StudentGroup("3G1TD1TP1");
            c=new StudentGroup("1G1TD1TP2");
            }
        catch (Exception e)
        {
            e.printStackTrace();
        }

        System.out.println(a.toString());
        System.out.println(a);
        System.out.println(b);
        System.out.println(c.toString());
        System.out.println(numberOfGroup);
    }
}
