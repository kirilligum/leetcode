#include <fstream>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <iterator>
#include <functional>
#include <array>
#include <random>
#include <tuple>
using namespace std;

pair<double,double> get_random_point(int size_boundary = 3) {
  random_device rd;
  mt19937 e(rd());
  uniform_int_distribution<> d(-size_boundary,size_boundary);
  return {d(e),d(e)};
}

array<pair<double,double>,4> build_rectangle(int size_boundary = 7) {
  array<pair<double,double>,4> r;
  random_device rd;
  mt19937 e(rd());
  uniform_int_distribution<> d(-size_boundary,size_boundary);
  r[0]={d(e),d(e)};
  r[1]={d(e),d(e)};
  double x3 =d(e);
  double sl = (r[1].second-r[0].second)/(r[1].first-r[0].first);
  double psl = (r[1].first-r[0].first)/(r[0].second-r[1].second);
  r[2]={x3,psl*(x3-r[0].first)+r[0].second};
  double x4 = (sl*r[2].first-psl*r[1].first+r[1].second-r[2].second)/(sl-psl);
  r[3]={x4,psl*(x4-r[1].first)+r[1].second};
  return r;
}

double dot( pair<double,double> a, pair<double,double> b) {
  return a.first*b.first+a.second*b.second;
}

bool in_rectangle(array<pair<double,double>,4> r, pair<double,double> p) {
  pair<double,double> r0p = {p.first-r[0].first, p.second-r[0].second};
  pair<double,double> r0r1 = {r[1].first-r[0].first, r[1].second-r[0].second};
  pair<double,double> r0r2 = {r[2].first-r[0].first, r[2].second-r[0].second};
  double r0pr0r1 = dot(r0p,r0r1);
  double r0r1r0r1 = dot(r0r1,r0r1);
  double r0pr0r2 = dot(r0p,r0r2);
  double r0r2r0r2 = dot(r0r2,r0r2);
  return 0<=r0pr0r1 && r0pr0r1<=r0r1r0r1 && 0<=r0pr0r2 && r0pr0r2<=r0r2r0r2;
}

int main(int argc, char const *argv[]) {
  auto r = build_rectangle(7);
  auto point = get_random_point();
  cout << "is " << "("<< point.first << "," << point.second << ") in rectangle? -- " << in_rectangle(r, point) << endl;

  for(auto i:r) cout << i.first << " " << i.second << endl;
  ofstream of("dat.txt");
  for(auto i:r) of << i.first << " " << i.second << endl;
  of << point.first << " " << point.second << endl;
  return 0;
}
