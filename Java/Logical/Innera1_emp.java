package Logical;

import java.sql.Date;
import java.util.Collections;
import java.util.LinkedList;

class a1_emp implements Comparable<a1_emp> {
    private int eid;
    private static int eid_counter = 0;
    private String name;
    private Date dob;
    private double salary;

    public a1_emp(String name, Date dob, double salary) {
        ++eid_counter;
        this.eid = eid_counter;
        this.name = name;
        this.dob = dob;
        this.salary = salary;
    }

    @Override
    public int compareTo(a1_emp o) {
        return this.salary > o.salary ? -1 : 1;
    }

    @Override
    public String toString() {
        return "(" + String.valueOf(eid) + "," + this.name + "," + this.salary + ")";
    }

}

public class Innera1_emp {
    @SuppressWarnings("deprecation")
    public static void main(String[] args) {
        LinkedList<a1_emp> emplist = new LinkedList<a1_emp>();

        LinkedList<a1_emp> emplist2 = new LinkedList<a1_emp>();
        emplist2.add(new a1_emp("A", new Date(2003,2,10), 20000));
        emplist2.add(new a1_emp("B", new Date(2003,4,20), 22000));

        emplist.add(new a1_emp("priya", new Date(2003, 04, 16), 500));
        emplist.add(new a1_emp("zeeya", new Date(2003, 04, 16), 2200));
        emplist.add(new a1_emp("riya", new Date(2003, 04, 16), 300));
        emplist.add(new a1_emp("jiya", new Date(2003, 04, 16), 200));

        Collections.sort(emplist);
        Collections.sort(emplist2);
        System.out.println("Sorted employee list based on salary");
        System.out.println(emplist);
        System.out.println(emplist2);

    }

}
