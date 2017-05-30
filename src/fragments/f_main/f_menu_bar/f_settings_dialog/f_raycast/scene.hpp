#ifndef __PROCALC_FRAGMENTS_F_RAYCAST_SCENE_HPP__
#define __PROCALC_FRAGMENTS_F_RAYCAST_SCENE_HPP__


#include <string>
#include <memory>
#include <list>
#include "fragments/f_main/f_menu_bar/f_settings_dialog/f_raycast/geometry.hpp"
#include "fragments/f_main/f_menu_bar/f_settings_dialog/f_raycast/camera.hpp"


class Scene {
  public:
    Scene(const std::string& mapFilePath);

    Camera camera;
    std::list<std::unique_ptr<Primitive>> primitives;
};


#endif
