/************************************************************
振り子のSimulation

Runge-Kutta
	運動方程式など、常微分方程式の解法
	
	
	http://hooktail.org/computer/index.php?Runge-Kutta%CB%A1
		note
			直感的でわかりやすい説明
			
	http://www.isc.meiji.ac.jp/~re00108/ch11/index.html
		note
			順を追って読んでいくと理解できる。
			上のpageと合わせて読むこと。
			
			sample sourceあり。
			そのまま使える。
************************************************************/

#pragma once

/************************************************************
************************************************************/
#include "ofMain.h"

/************************************************************
************************************************************/
class ofApp : public ofBaseApp{
	private:
		ofPoint pos_fix;
		float Length;
		
		float theta_rad;
		float omega;
		float g;
		
		
		double f1(double y1, double y2, double t);
		double f2(double y1, double y2, double t);

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
};
