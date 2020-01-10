
#include "igl/opengl/glfw/renderer.h"
#include "tutorial/sandBox/inputManager.h"
#include "igl/AABB.h"

using namespace std;

static void drawBox(igl::opengl::glfw::Viewer &viewer) {
	for (int i = 0; i <= 1; i++) {
		viewer.data_list[i].tree.init(viewer.data_list[i].V, viewer.data_list[i].F);
		igl::AABB<Eigen::MatrixXd, 3> tree = viewer.data_list[i].tree;
		Eigen::AlignedBox<double, 3> box = tree.m_box;
		viewer.data_list[i].drawBox(box, 0);
	}
}

int main(int argc, char *argv[])
{
  Display *disp = new Display(1000, 800, "Welcome");
  Renderer renderer;
  igl::opengl::glfw::Viewer viewer;

  viewer.load_configuration();

  viewer.MyTranslate(Eigen::Vector3f(0, 0, -0.8));
  viewer.data_list[0].MyTranslate(Eigen::Vector3f(0.5, 0, 0));
  viewer.data_list[1].MyTranslate(Eigen::Vector3f(-0.5, 0, 0));
  viewer.data_list[0].show_lines = false;
  viewer.data_list[1].show_lines = false;

  drawBox(viewer);

  Init(*disp);
  renderer.init(&viewer);
  disp->SetRenderer(&renderer);
  disp->launch_rendering(true);
  
  delete disp;
}
