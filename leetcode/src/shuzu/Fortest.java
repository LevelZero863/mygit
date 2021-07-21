package shuzu;

import java.util.ArrayList;
import java.util.List;

public class Fortest {
    public static void main(String[] args) {
        List<List<Integer>> list = new ArrayList <>();
        List<Integer> ll = new ArrayList<>();
        ll.add(1);
        ll.add(22);
        list.add(ll);
        System.out.println(list.get(0).get(0));
    }
}
