
public class Enkel extends Sohn{

	public Enkel(long a) {
		super(a);
	}
	
	public void summe() {
		double sum = 0;
		sum += ((Sohn)(this)).a;
		sum += ((Sohn)(this)).x;
		sum += ((Vater)(this)).x;
		sum += ((Vater)(this)).z;
		sum += ((Grossvater)(this)).x;
		sum += ((Grossvater)(this)).y;
		System.out.println(sum);
	}

}
