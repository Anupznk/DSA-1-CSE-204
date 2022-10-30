import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

class Point {
    int x, y;
    int index;

    public Point(int x, int y, int index) {
        this.x = x;
        this.y = y;
        this.index = index;
    }

    public Point() {

    }
}

class Pair {
    private Point a, b;
    private double dist;

    public Pair(Point a, Point b) {
        this.a = a;
        this.b = b;
        dist = Main.distance(a, b);
    }

    public Pair() {
        a = new Point();
        b = new Point();
    }

    public Point getA() {
        return a;
    }

    public Point getB() {
        return b;
    }

    public double getDist() {
        return dist;
    }

    public void setDist(double dist) {
        this.dist = dist;
    }

    @Override
    public String toString() {
        return "(" + a.x + "," + a.y + ")\n" + "(" + b.x + "," + b.y + ")";
    }
}

class TwoPairs {
    Pair closestPair, secondClosestPair;

    public TwoPairs(Pair closestPair, Pair secondClosestPair) {
        this.closestPair = closestPair;
        this.secondClosestPair = secondClosestPair;
    }

    public TwoPairs() {
        closestPair = new Pair();
        secondClosestPair = new Pair();
    }

    public Pair getClosestPair() {
        return closestPair;
    }

    public void setClosestPair(Pair closestPair) {
        this.closestPair = closestPair;
    }

    public Pair getSecondClosestPair() {
        return secondClosestPair;
    }

    public void setSecondClosestPair(Pair secondClosestPair) {
        this.secondClosestPair = secondClosestPair;
    }
}

public class SecondClosestPoints {

    public static void main(String[] args) {
        List<Point> arrX = new ArrayList<>();
        List<Point> arrY = new ArrayList<>();
        try {
            File myFile = new File("test.txt");
            Scanner myReader = new Scanner(myFile);
            int n = myReader.nextInt();

            for (int i = 0; i < n; i++) {
                int x = myReader.nextInt();
                int y = myReader.nextInt();
                arrX.add(new Point(x, y, i));
                arrY.add(new Point(x, y, i));
            }
            myReader.close();
        } catch (FileNotFoundException e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }

        MergeSort.mergeSort(arrX, 0, arrX.size() - 1, true);
        MergeSort.mergeSort(arrY, 0, arrY.size() - 1, false);

        TwoPairs solution = closestPairs(arrX, arrY, 0);
        System.out.println(solution.getSecondClosestPair().getA().index + " " + solution.getSecondClosestPair().getB().index);
        System.out.printf("%.4f", solution.getSecondClosestPair().getDist());

    }

    public static double distance(Point a, Point b) {
        return Math.sqrt(Math.pow((a.x - b.x), 2) + Math.pow((a.y - b.y), 2));
    }

    public static TwoPairs closestInThree(Pair a, Pair b, Pair c) {
        List<Pair> pairs = new ArrayList<>();
        pairs.add(a);
        pairs.add(b);
        pairs.add(c);
        pairs.sort(new Comparator<Pair>() {
            @Override
            public int compare(Pair o1, Pair o2) {
                if (o1.getDist() > o2.getDist())
                    return 1;
                else
                    return -1;
            }
        });
        TwoPairs twoPairs = new TwoPairs(pairs.get(0), pairs.get(1));
        return twoPairs;
    }

    private static TwoPairs closestPairs(List<Point> arrX, List<Point> arrY, int level) {
        if (arrX.size() == 2) {
            TwoPairs pairs = new TwoPairs();
            pairs.setClosestPair(new Pair(arrX.get(0), arrX.get(1)));
            Pair secondClosest = new Pair();
            secondClosest.setDist(Double.MAX_VALUE);
            pairs.setSecondClosestPair(secondClosest);

            return pairs;
        }
        if (arrX.size() == 3) {
            Pair a = new Pair(arrX.get(0), arrX.get(1));
            Pair b = new Pair(arrX.get(1), arrX.get(2));
            Pair c = new Pair(arrX.get(0), arrX.get(2));

            TwoPairs twoPairs = closestInThree(a, b, c);

            return twoPairs;
        }

        int mid = arrX.size() / 2;
        Point midPoint = arrX.get(mid);

        List<Point> arrXLeft = new ArrayList<>();
        List<Point> arrXRight = new ArrayList<>();
        List<Point> arrYRight = new ArrayList<>();
        List<Point> arrYLeft = new ArrayList<>();

        for (int i = 0; i < mid; i++) {
            arrXLeft.add(arrX.get(i));
        }
        for (int i = mid; i < arrX.size(); i++) {
            arrXRight.add(arrX.get(i));
        }

        for (int i = 0; i < arrY.size(); i++) {
            if (arrY.get(i).x <= arrXLeft.get(arrXLeft.size() - 1).x) {
                arrYLeft.add(arrY.get(i));
            } else {
                arrYRight.add(arrY.get(i));
            }
        }

        TwoPairs pairsLeft = closestPairs(arrXLeft, arrYLeft, level + 1);
        TwoPairs pairsRight = closestPairs(arrXRight, arrYRight, level + 1);

        List<Pair> pairs = new ArrayList<>();
        pairs.add(pairsLeft.getClosestPair());
        pairs.add(pairsLeft.getSecondClosestPair());
        pairs.add(pairsRight.getClosestPair());
        pairs.add(pairsRight.getSecondClosestPair());

        pairs.sort(new Comparator<Pair>() {
            @Override
            public int compare(Pair o1, Pair o2) {
                if (o1.getDist() > o2.getDist())
                    return 1;
                else
                    return -1;
            }
        });

        TwoPairs finalPairs = new TwoPairs(pairs.get(0), pairs.get(1));
        double d = finalPairs.getSecondClosestPair().getDist();

        List<Point> stripPoints = new ArrayList<>();
        for (int i = 0; i < arrY.size(); i++) {
            if (Math.abs(arrY.get(i).x - midPoint.x) <= d) {
                stripPoints.add(arrY.get(i));
            }
        }

        for (int i = 0; i < stripPoints.size(); i++) {
            for (int j = 1; j <= 7; j++) {
                if (i + j >= stripPoints.size())
                    break;
                double currDist = distance(stripPoints.get(i), stripPoints.get(i + j));
                if (currDist < finalPairs.getClosestPair().getDist()) {
                    finalPairs.setSecondClosestPair(finalPairs.getClosestPair());
                    finalPairs.setClosestPair(new Pair(stripPoints.get(i), stripPoints.get(i + j)));

                } else if (currDist < finalPairs.getSecondClosestPair().getDist() && currDist > finalPairs.getClosestPair().getDist()) {
                    finalPairs.setSecondClosestPair(new Pair(stripPoints.get(i), stripPoints.get(i + j)));
                }
            }
        }
        return finalPairs;
    }
}

