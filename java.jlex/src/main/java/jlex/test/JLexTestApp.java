package jlex.test;

import jlex.generated.YyLex;
import jlex.generated.YyToken;

import java.io.StringReader;
import java.util.ArrayList;
import java.util.List;

/**
 * @author hwanseok on 2021/10/08
 */
public class JLexTestApp {

    public static void main (String... args) throws Exception {
        String rule = "abc != 123";
        YyLex yyLex = new YyLex(new StringReader(rule));

        YyToken t;
        List<YyToken> list = new ArrayList<YyToken>();
        while ((t = yyLex.yylex()) != null) {
            list.add(t);
            System.out.println(t);
        }
    }
}
