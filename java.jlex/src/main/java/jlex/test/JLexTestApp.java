package jlex.test;

import com.sun.tools.javac.util.StringUtils;
import jlex.generated.YyLex;
import jlex.generated.YyToken;

import java.io.StringReader;
import java.util.*;

/**
 * @author hwanseok on 2021/10/08
 */
public class JLexTestApp {

    public static void main (String... args) throws Exception {
        String rule = "1 + 2";
        List<YyToken> lexicalResult = lexicalAnalysis(rule);

        Map<String, Long> m = new HashMap<>();
        m.put("hwanseok", 1L);
        m.put("age", 27L);
        m.put("now", 2021L);
        Object syntaxAnalysis = syntaxAnalysis(lexicalResult, m);
        if(syntaxAnalysis instanceof Boolean){
            System.out.println((Boolean)syntaxAnalysis);
        }else if(syntaxAnalysis instanceof ArrayList){
            System.out.println(((ArrayList<?>) syntaxAnalysis).indexOf(0));
        }else if(syntaxAnalysis instanceof HashMap){
            System.out.println(((HashMap<?,?>) syntaxAnalysis));
        } else{
            System.out.println("Invalid Result Type");
        }
    }

    public static List<YyToken> lexicalAnalysis(String input) throws Exception {
        YyLex yyLex = new YyLex(new StringReader(input));

        YyToken t;
        List<YyToken> list = new ArrayList<YyToken>();
        while ((t = yyLex.yylex()) != null) {
            list.add(t);
            System.out.println(t);
        }
        return list;
    }

    public static Object syntaxAnalysis(List<YyToken> tokenList, Map<String, Long> m){
        // 구문 분석을 진행...
        // 의존성이 적게 구문 분석의 기능을 추가할 수 있음
        String operator = (String) tokenList.get(1).value;
        Long operand1 = (Long) tokenList.get(0).value;
        Long operand2 = (Long) tokenList.get(2).value;
        Long threshold = 0L;
        if(operator.equals("+")){
            threshold = operand1 + operand2;
        }

        Map<String, Long> ret = new HashMap<>();
        for(String key : m.keySet()){
            if(m.get(key) >= threshold){
                ret.put(key, m.get(key));
            }
        }
        return ret;
    }
}
