#pragma once
#include <string>
#include <cmath>

class Distance {

public:
	Distance(double lat, double lon) : m_lat(lat), m_lon(lon) {}
	double get_latitude() const {return m_lat;}
	double get_longitude() const {return m_lon;}
	double dist() const {return hypot(m_lat, m_lon);}

private:
	double m_lat;
	double m_lon;
};

class Coordinates {
public:
	Coordinates(std::string cityName, double lat, double lon) : 
		m_cityName(cityName), m_lat(lat), m_lon(lon) {
		}

	void move(double latShift, double lonShift) {
		m_lat += latShift;
		m_lon += lonShift;
	}
	void print() const {
		std::cout << m_cityName << ": ";
		m_lat < 0 ? std::cout << -m_lat << "S" : std::cout << m_lat << "N";
		std::cout << " ";
		m_lon < 0 ? std::cout << -m_lon << "W" << std::endl 
			: std::cout << m_lon << "E" << std::endl;
	}

	double& latitude() {return m_lat;}
	double latitude() const {return m_lat;}
	
	double longitude() const {return m_lon;}
	std::string name() const {return m_cityName;}

	Distance distance(Coordinates target) {
		return Distance(m_lat-target.latitude(), m_lon-target.longitude());
	}

	Coordinates closestFrom(const Coordinates& p1, const Coordinates& p2) const {
		double latDiff1 = m_lat - p1.latitude();
		double latDiff2 = m_lat - p2.latitude();
		double lonDiff1 = m_lon - p1.longitude();
		double lonDiff2 = m_lon - p2.longitude();

		if (Distance(latDiff1, lonDiff1).dist() < Distance(latDiff2, lonDiff2).dist()) {
			return p1;
		}
		else {
			return p2;
		}
	}

private:
	std::string m_cityName;
	double m_lat;
	double m_lon;
};
