struct point{
  int x,y;  
  bool operator<(const point& o) const {
    return (x != o.x ? x < o.x : y < o.y); 
  }
};
const int N = 1e5+5;
vector<point> node;

bool inline cmp1(const point& p1, const point& p2) {return p1.x != p2.x ? p1.x < p2.x : p1.y < p2.y;};
bool inline cmp2(const point& p1, const point& p2) {
    ll x1 = p1.x - node[0].x;
    ll y1 = p1.y - node[0].y;
    ll x2 = p2.x - node[0].x;
    ll y2 = p2.y - node[0].y;
    ll o = x1*y2 - x2*y1;
    return o > 0;
}
bool inline rightTurn(const point& p1, const point& p2, const point& p3) {
    ll x1 = p2.x - p1.x;
    ll y1 = p2.y - p1.y;
    ll x2 = p3.x - p1.x;
    ll y2 = p3.y - p1.y;
    return (x1*y2-x2*y1) <= 0;
}
double inline angle(const point& p1, const point& p2, const point& p3) {
    ll x1 = p1.x - p2.x;
    ll y1 = p1.y - p2.y;
    ll x2 = p3.x - p2.x;
    ll y2 = p3.y - p2.y;
    double l1 = sqrt(x1*x1+y1*y1);
    double l2 = sqrt(x2*x2+y2*y2);
    return acos((x1*x2+y1*y2)/(l1*l2))*180/acos(-1);
}
void convex_hull(vector<point>& node, vector<point>& st) {
    sort(node.begin(), node.end(), cmp1);
    sort(node.begin()+1, node.end(), cmp2);
    st.push_back(node[0]);
    st.push_back(node[1]);
    for (int i = 2; i < node.size(); ++i) {
        while (st.size() > 1 && rightTurn(st[st.size()-2], st[st.size()-1], node[i])) st.pop_back();
        st.push_back(node[i]);
    } 
}
