class AccessModifier{
  public String publicMsg="Public";
          String defaultMsg="Default";
  private String pvtMsg="Private";
  protected String protectedMsg="Protected";

}
public class Main{
  public static void main(String[] args) {
   AccessModifier obj = new AccessModifier();
   System.out.println(obj.publicMsg);
    System.out.println(obj.defaultMsg);
    System.out.println(obj.pvtMsg);
    System.out.println(obj.protectedMsg);
  }
}
