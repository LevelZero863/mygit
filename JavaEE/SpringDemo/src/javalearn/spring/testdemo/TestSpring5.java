package javalearn.spring.testdemo;

import javalearn.spring.User;
import jdk.jfr.StackTrace;
import org.junit.Test;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;


public class TestSpring5 {

    @Test
    public void testAdd() {
        ApplicationContext context = new ClassPathXmlApplicationContext("bean1.xml");
        User user = context.getBean("user", User.class);
        System.out.println(user);
        user.add();

    }
}
