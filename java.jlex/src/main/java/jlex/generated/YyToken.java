package jlex.generated;

public class YyToken {
    public final static int FUNCTION = 91;
    /**
     * BASE_VAL 이후의 번호는 값들을 의미한다. BASE_VAL 이하의 토큰들은 오퍼랜드들을 갖는 토큰들이다.
     */
    public final static int BASE_VAL = 100;
    public final static int NULL = 101;
    public final static int BOOLEAN = 102;
    public final static int DECIMAL = 103;
    public final static int REAL = 104;
    public final static int OBJECT = 105;
    public final static int STRING = 106;
    public final static int VARIABLE = 120;
    public final static int PHRENTHESIS_OPEN = 50;
    public final static int PHRENTHESIS_CLOSE = 51;
    public final static int BRACKET_OPEN = 1001;
    public final static int BRACKET_CLOSE = 1002;
    public final static int COMMA = 1003;
    YyToken(int index, Object value) {
        this.index = index;
        this.value = value;
    }
    public int index;
    public Object value;
    public String toString() {
        return "YyToken #"+index+": "+value;
    }
    public boolean equals(Object o) {
        if (o instanceof YyToken) {
            YyToken param = (YyToken) o;
            return (param.index == this.index) && (this.value.equals(param.value));
        } else {
            return false;
        }
    }
    public int hashCode() {
        return toString().hashCode();
    }
}