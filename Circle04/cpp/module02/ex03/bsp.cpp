#include "Point.hpp"

// bool isPointInsideTriangle(float x, float y, float x1, float y1, float x2, float y2, float x3, float y3) {
//     float d1 = ((x - x2) * (y1 - y2) - (x1 - x2) * (y - y2));
//     float d2 = ((x - x3) * (y2 - y3) - (x2 - x3) * (y - y3));
//     float d3 = ((x - x1) * (y3 - y1) - (x3 - x1) * (y - y1));

//     // 각 꼭지점을 기준으로 계산한 값의 부호가 모두 같으면 삼각형 안에 있는 것
//     return ((d1 > 0 && d2 > 0 && d3 > 0) || (d1 < 0 && d2 < 0 && d3 < 0));
// }

bool	bsp(Point const a, Point const b, Point const c, Point const point) {
	float	d1 = ((point.getX().toFloat() - b.getX().toFloat()) * (a.getY().toFloat() - b.getY().toFloat()) - (a.getX().toFloat() - b.getX().toFloat()) * (point.getY().toFloat() - b.getY().toFloat()));
	float	d2 = ((point.getX().toFloat() - c.getX().toFloat()) * (b.getY().toFloat() - c.getY().toFloat()) - (b.getX().toFloat() - c.getX().toFloat()) * (point.getY().toFloat() - c.getY().toFloat()));
	float	d3 = ((point.getX().toFloat() - a.getX().toFloat()) * (c.getY().toFloat() - a.getY().toFloat()) - (c.getX().toFloat() - a.getX().toFloat()) * (point.getY().toFloat() - a.getY().toFloat()));

	return ((d1 > 0 && d2 > 0 && d3 > 0) || (d1 < 0 && d2 < 0 && d3 < 0));
}