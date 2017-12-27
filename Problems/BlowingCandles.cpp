
#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
 #define REMOVE_REDUNDANT // To eliminate redundant points from hull

using namespace std;
typedef long double T;
const T EPS = 1e-7;
struct PT {
  T x, y;
  PT() {}
  PT(T x, T y) : x(x), y(y) {}
  bool operator<(const PT &rhs) const { return make_pair(y,x) < make_pair(rhs.y,rhs.x); }
  bool operator==(const PT &rhs) const { return make_pair(y,x) == make_pair(rhs.y,rhs.x); }

  PT operator + (const PT &p) const { return PT(x+p.x, y+p.y); }
  PT operator - (const PT &p) const { return PT(x-p.x, y-p.y); }
  PT operator * (double c)     const { return PT(x*c,   y*c  ); }
  PT operator / (double c) const { return PT(x/c, y/c ); }
};

T cross(PT p, PT q) { return p.x*q.y-p.y*q.x; }
T area2(PT a, PT b, PT c) { return cross(a,b) + cross(b,c) + cross(c,a); }

#ifdef REMOVE_REDUNDANT
bool between(const PT &a, const PT &b, const PT &c) {
  return (fabs(area2(a,b,c)) < EPS && (a.x-b.x)*(c.x-b.x) <= 0 && (a.y-b.y)*(c.y-b.y) <= 0);
}
#endif

void ConvexHull(vector<PT> &pts) {
  sort(pts.begin(), pts.end());
  pts.erase(unique(pts.begin(), pts.end()), pts.end());
  vector<PT> up, dn;
  for (int i = 0; i < pts.size(); i++) {
    while (up.size() > 1 && area2(up[up.size()-2], up.back(), pts[i]) >= 0) up.pop_back();
    while (dn.size() > 1 && area2(dn[dn.size()-2], dn.back(), pts[i]) <= 0) dn.pop_back();
    up.push_back(pts[i]);
    dn.push_back(pts[i]);
  }
  pts = dn;
  for (int i = (int) up.size() - 2; i >= 1; i--) pts.push_back(up[i]);

#ifdef REMOVE_REDUNDANT
  if (pts.size() <= 2) return;
  dn.clear();
  dn.push_back(pts[0]);
  dn.push_back(pts[1]);
  for (int i = 2; i < pts.size(); i++) {
    if (between(dn[dn.size()-2], dn[dn.size()-1], pts[i])) dn.pop_back();
    dn.push_back(pts[i]);
  }
  if (dn.size() >= 3 && between(dn.back(), dn[0], dn[1])) {
    dn[0] = dn.back();
    dn.pop_back();
  }
  pts = dn;
#endif
}
long double dot(PT p, PT q)     { return p.x*q.x+p.y*q.y; }
long double dist2(PT p, PT q) { return dot(p-q,p-q); }
PT ProjectPointLine(PT a, PT b, PT c) {
  return a + (b-a)*dot(c-a, b-a)/dot(b-a, b-a);
}
long double distPointLine(PT a, PT b, PT c)
{
	return sqrt(dist2(ProjectPointLine(a,b,c),c));
}
int main()
{
	while (true)
	{
		long long N,R;
		cin>>N;
		if (cin.eof())
			break;
		cin>>R;
		vector<PT> puntuak;
		for (int i=0;i<N;i++)
		{
			long long x,y;
			cin>>x;
			cin>>y;
			puntuak.push_back(PT(x,y));
		}

		ConvexHull(puntuak);
		long double width=0;
		int farthest=-1;
		long double farthestDist=-1;
		for (int i=0;i<puntuak.size();i++)
			;//cout<<puntuak[i].x<<" "<<puntuak[i].y<<endl;
		if (puntuak.size()==2)
		{
			cout<<"0.0"<<endl;
			continue;
		}
		for (int i=0;i<puntuak.size();i++)
		{
			if (i==0)
			{
				PT a=puntuak[0];
				PT b=puntuak[1];
				for (int j=2;j<puntuak.size();j++)
				{
					long double dist=distPointLine(a,b,puntuak[j]);
					//cout<<a.x<<" "<<a.y<<"  "<<b.x<<" "<<b.y<<" "<<puntuak[j].x<<" "<<puntuak[j].y<<" "<<dist<<endl;
					if (dist>farthestDist)
					{
						farthestDist=dist;
						farthest=j;
					}
				}
				width=farthestDist;
			}
			else
			{
				PT a=puntuak[i];
				PT b;
				if (i+1>=puntuak.size())
					b=puntuak[0];
				else
					b=puntuak[i+1];
				farthestDist=distPointLine(a,b,puntuak[farthest]);
				//cout<<a.x<<" "<<a.y<<"  "<<b.x<<" "<<b.y<<" "<<puntuak[farthest].x<<" "<<puntuak[farthest].y<<" "<<farthestDist<<endl;
				while (true)
				{
					int next=farthest+1;
					if (next>=puntuak.size())
						next=0;
					long double dist=distPointLine(a,b,puntuak[next]);
					//cout<<a.x<<" "<<a.y<<"  "<<b.x<<" "<<b.y<<" "<<puntuak[next].x<<" "<<puntuak[next].y<<" "<<dist<<endl;
					if (dist>farthestDist)
					{
						farthest=next;
						farthestDist=dist;
					}
					else
						break;
				}
				if (farthestDist<width)
				{
					width=farthestDist;
				}
			}
			//cout<<i<<" "<<width<<" "<<farthestDist<<" "<<farthest<<endl;
		}
		cout.precision(6);
		cout<<fixed<<width<<endl;
	}
}
