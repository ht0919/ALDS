#include <iostream>
#include <vector>
using namespace std;

// 16.1: 点を表す構造体
struct Point { double x, y; };

// 16.2: ベクトルを表す構造体
typedef Point Vector;

// 16.3: 線分を表す構造体
struct Segment {
  Point p1, p2;
};

// 16.4: 直線を表す構造体
typedef Segment Line;

// 16.5: 円を表すクラス
class Circle {
public:
    Point c;
    double r;
    Circle(Point c = Point(), double r = 0.0): c(c), r(r) {}
};

// 16.6: 多角形の表現
typedef vector<Point> Polygon;

// 16.7: 点・ベクトルに対する演算子の定義
double x, y;
Point operator + ( Point &p ) {
  return Point(x + p.x, y + p.y);
}

Point operator - ( Point &p ) {
  return Point(x - p.x, y - p.y);
}

Point operator * ( double k ) {
  return Point(x * k, y * k);
}

// 16.8: ベクトルに対する演算の例
Vector a, b, c, d;
c = a - b;      // ベクトルの差
d = a * 2.0;    // ベクトルのスカラー倍

// 16.9: ベクトルのノルムと大きさ
double norm(Vector a) {
    return a.x * a.x + a.y * a.y;
}

double abs(Vector a) {
    return sqrt(norm(a));
}

// 16.10: Point クラス
#define EPS (1e - 10)
#define equals(a, b) (fabs((a) - (b)) < EPS)

class Point{
  public:
    double x, y;

  Point(double x = 0, double y = 0): x(x), y(y) {}

  Point operator + (Point p)  { return Point(x + p.x, y + p.y); }
  Point operator - (Point p)  { return Point(x - p.x, y - p.y); }
  Point operator * (double a) { return Point(a * x, a * y); }
  Point operator / (double a) { return Point(x / a, y / a); }

  double abs()  { return sqrt(norm()); }
  double norm() { return x * x + y * y; }

  bool operator < (const Point &p) const {
    return x != p.x ? x < p.x : y < p.y;
  }

  bool operator == (const Point &p) const {
    return fabs(x - p.x) < EPS && fabs(y - p.y) < EPS;
  }
};

typedef Point Vector;

// 16.11: ベクトル a と b の内積
double dot(Vector a, Vector b){
  return a.x * b.x + a.y * b.y;
}

// 16.12: ベクトル a と b の外積
double cross(Vector a, Vector b) {
  return a.x * b.y - a.y * b.x;
}

// 16.13: ベクトル a と b の直交判定
bool isOrthogonal(Vector a,  Vector b) {
  return equals(dot(a, b), 0.0);
}

bool isOrthogonal(Point a1, Point a2, Point b1, Point b2) {
  return isOrthogonal(a1 - a2, b1 - b2);
}

bool isOrthogonal(Segment s1, Segment s2) {
  return equals(dot(s1.p2 - s1.p1, s2.p2 - s2.p1), 0.0);
}

// 16.14: ベクトル a と b の平行判定
bool isParallel(Vector a, Vector b) {
  return equals(cross(a, b), 0.0);
}

bool isParallel(Point a1, Point a2, Point b1, Point b2) {
  return isParallel(a1 - a2, b1 - b2);
}

bool isParallel(Segment s1, Segment s2) {
  return equals(cross(s1.p2 - s1.p1, s2.p2 - s2.p1), 0.0);
}

// 16.15: 線分 s に対する点 p の射影
Point project(Segment s, Point p) {
    Vector base = s.p2 - s.p1;
    double r = dot(p - s.p1, base) / norm(base);
    return s.p1 + base * r;
}

// 16.16: 線分 s を対称軸とした点 p の線対称の点
Point reflect(Segment s, Point p) {
    return p + (project(s, p) - p) * 2.0;
}

// 16.17: 点 a と点 b の距離
double getDistance(Point a, Point b) {
    return abs(a - b);
}

// 16.18: 直線 l と p 点の距離
double get getDistanceLP(Line l, Point p) {
    return abs(cross(l.p2 - l.p1, p - l.p1) / abs(l.p2 - l.p1));
}

// 16.19: 線分 s と点 p の距離
double getDistanceSP(Segment s, Point p) {
    if ( dot(s.p2 - s.p1, p - s.p1) < 0.0 ) return abs(p - s.p1);
    if ( dot(s.p1 - s.p2, p - s.p2) < 0.0 ) return abs(p - s.p2);
    return getDistanceLP(s, p);
}

// 16.20: 線分 s1 と線分 s2 の距離
double getDistance(Segment s1, Segment s2) {
    if ( intersect(s1, s2) ) return 0.0;
    return min(min(getDistanceSP(s1, s2.p1), getDistanceSP(s1, s2.p2)),
               min(getDistanceSP(s2, s1.p1), getDistanceSP(s2, s1.p2)));
}

// 16.21: 反時計回りCCW
static const int COUNTER_CLOCKWISE = 1;
static const int CLOCKWISE = -1;
static const int ONLINE_BACK = 2;
static const int ONLINE_FRONT = -2;
static const int ON_SEGMENT = 0;

int ccw(Point p0, Point p1, Point p2) {
    Vector a = p1 - p0;
    Vector b = p2 - p0;
    if ( cross(a, b) > EPS ) return COUNTER_CLOCKWISE;
    if ( cross(a, b) < -EPS ) return CLOCKWISE;
    if ( dot(a, b) < -EPS ) return ONLINE_BACK;
    if ( a.norm() < b.norm() ) return ONLINE_FRONT;

    return ON_SEGMENT;
}

// 16.22: 線分 p1p2 と線分 p3p4 の交差判定
bool intersect(Point p1, Point p2, Point p3, Point p4) {
    return ( ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 &&
             ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0 );
}

bool intersect(Segment s1, Segment s2) {
    return intersect(s1.p1, s1.p2, s2.p1, s2.p2);
}

// 16.23: 線分 s1 と線分 s2 の交点
Point getCrossPoint(Segment s1, Segment s2) {
    Vector base = s2.p2 - s2.p1;
    double d1 = abs(cross(base, s1.p1 - s2.p1));
    double d2 = abs(cross(base, s1.p2 - s2.p1));
    double t = d1 / (d1 + d2);
    return s1.p1 + (s1.p2 - s1.p1) * t;
}

// 16.24: 円 c と線分 l の交点
pair<Point, Point> getCrossPoints(Circle c, Line l) {
    assert(intersect(c, l));
    Vector pr = project(l, c.c);
    Vector e = (l.p2 - l.p1) / abs(l.p2 - l.p1);
    double base = sqrt(c.r * c.r - norm(pr - c.c));
    return make_pair(pr + e * base, pe - e * base);
}

// 16.25: 円 c1 と円 c2 の交点
double arg(Vector p) { return atan2(p.y, p.x); }
Vector polar(double a, double r) { return Point(cos(r) * a, sin(r) * a); }

pair<Point, Point> getCrossPoints(Circle c1, Circle c2) {
    assert(intersect(c1, c2));
    double d = abs(c1.c - c2.c);
    double a = acos((c1.r * c1.r + d * d - c2.r * c2.r) / (2 * c1.r * d));
    double t = arg(c2.c - c1.c);
    return make_pair(c1.c + polar(c1.r, t + a), c1.c + polar(c1.r, t - a));
}

// 16.26: 点の内包
/*
  IN 2
  ON 1
  OUT 0
*/
int contains(Polygon g, Point p) {
    int n = g.size();
    bool x = false;
    for ( int i = 0; i < n; i++ ) {
        Point a = g[i] - p, b = g[(i + 1) % n] - p;
        if ( abs(cross(a, b)) < EPS && dot(a, b) < EPS ) return 1;
        if ( a.y > b.y ) swap(a, b);
        if ( a.y < EPS && EPS < b.y && cross(a, b) > EPS ) x = !x;
    }
    return ( x ? 2 : 0 );
}

// 16.27: アンドリューのアルゴリズム
Polygon andrewScan( Polygon s ) {
    Polygon u, l;
    if ( s.size() < 3 ) return s;
    sort(s.begin(), s.end()); // x, y を基準に昇順にソート
    // x が小さいものから２つ u に追加
    u.push_back(s[0]);
    u.push_back(s[1]);
    // x が大きいものから２つ l に追加
    l.push_back(s[s.size() - 1]);
    l.push_back(s[s.size() - 2]);

    // 凸包の上部を生成
    for ( int i = 2; i < s.size(); i++ ) {
        for ( int n = u.size(); n >= 2 && ccw(u[n-2], u[n-1], s[i]) != CLOCKWISE; n--) {
            u.pop_back();
        }
        u.push_back(s[i]);
    }

    // 凸包の下部を生成
    for ( int i = s.size() - 3; i >= 0; i-- ) {
        for ( int n = l.size(); n >= 2 && ccw(l[n-2], l[n-1], s[i]) != CLOCKWISE; n--) {
            l.pop_back();
        }
        l.push_back(s[i]);
    }

    // 時計回りになるように凸包の点の列を生成
    reverse(l.begin(), l.end());
    for ( int i = u.size() - 2; i >= 1; i-- ) l.push_back(u[i]);

    return l;
}

// 16.28: 平面走査
// 端点の種類
#define BOTTOM 0
#define LEFT 1
#define RIGHT 2
#define TOP 3

class EndPoint {
public:
    Point p;
    int seg, st; // 入力線分のID, 端点の種類
    EndPoint() {}
    EndPoint(Point p, int seg, int st): p(p), seg(seg), st(st) {}

    bool operator < (const EndPoint &ep) const {
        // y 座標が小さい順に整列
        if ( p.y == ep.p.y ) {
            return st < ep.st; // y が同一の場合は、下端点、左端点、右端点、上端点の順に並べる
        } else return p.y < ep.p.y;
    }
};

EndPoint EP[2 * 100000]; // 端点のリスト

// 線分交差問題：マンハッタン幾何
int manhattanIntersection(vector<Segment> S) {
    int n = S.size();

    for ( int i = 0, k = 0; i < n; i++ ) {
        // 端点 p1, p2 が左下を基準に並ぶように調整
        if ( S[i].p1.y == S[i].p2.y ) {
            if ( S[i].p1.x > S[i].p2.x ) swap(S[i].p1, S[i].p2);
        } else if ( S[i].p1.y > S[i].p2.y ) swap(S[i].p1, S[i].p2);

        if ( S[i].p1.y == S[i].p2.y ) { // 水平線分を端点リストに追加
            EP[k++] = EndPoint(S[i].p1, i, LEFT);
            EP[k++] = EndPoint(S[i].p2, i, RIGHT);
        } else {                         // 垂直線分を端点リストに追加
            EP[k++] = EndPoint(S[i].p1, i, BOTTOM);
            EP[k++] = EndPoint(S[i].p2, i, TOP);
        }
    }

    sort(EP, EP + (2 * n)); // 端点の y 座標に関して昇順に整列

    set<int> BT;            // 二分木探索
    BT.insert(1000000001)   // 番兵を設置
    int cnt = 0;

    for ( int i = 0; i < 2 * n; i++ ) {
        if ( EP[i].st == TOP ) {
            BT.erase(EP[i].p.x);    // 上端点を削除
        } else if ( EP[i].st == BOTTOM ) {
            BT.insert(EP[i].p.x);   // 下端点を追加
        } else if ( EP[i].st == LEFT ) {
            set<int>::iterator b = BT.lower_bound(S[EP[i].seg].p1.x); // O(log n)
            set<int>::iterator e = BT.upper_bound(S[EP[i].seg].p2.x); // O(log n)
            cnt += distance(b, e); // b と e の距離（点の数）を加算, O(k)
        }
    }

    return cnt;
}