public class Student {

    private String firstName;
    private String lastName;
    private static int totalNumberOfStudents;

    public Student(String firstName, String lastName) {
        this.firstName = firstName;
        this.lastName = lastName;
        Student.totalNumberOfStudents++;
    }
    
    public String getFirstName() {
        return firstName;
    }

    public String getLastName() {
        return lastName;
    }

    public int getTotalNumberOfStudents() {
        return totalNumberOfStudents;
    }

    public void setFirstName(String firstName) {
        this.firstName = firstName;
    }

    public void setLastName(String lastName) {
        this.lastName = lastName;
    }

    public static void setTotalNumberOfStudents(int totalNumberOfStudents) {
        Student.totalNumberOfStudents = totalNumberOfStudents;
    }

    @Override
    public String toString() {
        return "Hello "+this.firstName+" "+this.lastName+"";
    }

    @Override
    protected void finalize(){
        totalNumberOfStudents--;
    }
    public static void main(String[] args) {
        Student student1 = new Student("Paul","Dupond");
        System.out.println(student1.toString());
        System.out.println(totalNumberOfStudents);
        Student student2 = new Student("Maxime", "Peloutier");
        System.out.println(student2.toString());
        System.out.println(totalNumberOfStudents);
    }
}
