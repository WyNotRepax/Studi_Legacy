/**
 * Quadratisches Spielfeld der Gr��e f�r ein "Zahlen-Slider"-Puzzle.
 * 
 * @author Friedhelm Tappe, Prof. Dr.-Ing. Heiko Tapken
 * @version 25.10.2014
 */

public class Spielfeld {
	private int sizeXY;

	private int[][] field;

	public Spielfeld(int maxX) {
		this.sizeXY = maxX;
		this.field = new int[this.sizeXY][this.sizeXY];
		this.init();
		// ...

	}

	/**
	 * Initialisieren des Spielfeldes mit einem g�ltigen Endzustand
	 */
	public void init() {
		int n = 0;
		while (n < sizeXY * sizeXY) {
			this.field[n / sizeXY][n % sizeXY] = n;
			n++;
		}
	}

	/**
	 * 
	 * @param counter
	 *            Initialisiere Spielfeld durch eine Anzahl Verschiebungen aus
	 *            einem g�ltigen Endzustand. Stellt zun�chst einen g�ltigen
	 *            Endzustand her.
	 */
	public void randomInit(int counter) {
	}

	/**
	 * Setzen von xfrei und yfrei Die freie Zelle ist die Zelle mit dem Wert
	 * sizeXY*sizeXY
	 */
	private void bestimmeXYfrei() {
	}

	/**
	 * Kann die Zelle an der Position x,y verschoben werden? Es wird �berpr�ft,
	 * ob eine Nachbarzelle der Zelle an x, y die freie Zelle ist.
	 * 
	 * @param x
	 *            Spalte der Zelle
	 * @param y
	 *            Zeile der Zelle
	 * @return Zelle verschiebbar
	 */
	private boolean zelleOK(int x, int y) {
		return false;
	}

	public boolean verschiebeZelle(int x, int y) {
		return false;
	}

	/**
	 * �berpr�fung, ob das Puzzle gel�st ist.
	 * 
	 * @return Puzzle gel�st?
	 */
	public boolean fertig() {
		return false;
	}

	/**
	 * Textausgabe einer einzelnen Zelle
	 * 
	 * @param x
	 *            Spalte der Zelle
	 * @param y
	 *            Zeile der Zelle
	 * @return Beschriftung der Zelle
	 */
	public String toStringZelle(int x, int y) {
		return String.valueOf((field[y][x] == 0) ? "" : field[y][x]);
	}

	/**
	 * Gibt gr��e des Spielfelds zur�ck
	 * 
	 * @return gr��e des Spielfelds
	 */
	public int getSizeXY() {
		return this.sizeXY;
	}

}
