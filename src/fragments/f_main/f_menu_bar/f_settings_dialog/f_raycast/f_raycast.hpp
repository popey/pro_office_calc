#ifndef __PROCALC_FRAGMENTS_F_RAYCAST_HPP__
#define __PROCALC_FRAGMENTS_F_RAYCAST_HPP__


#include <memory>
#include <map>
#include <QOpenGLWidget>
#include <QTimer>
#include "fragment.hpp"
#include "fragments/f_main/f_menu_bar/f_settings_dialog/f_raycast/scene.hpp"


class QPaintEvent;


struct FRaycastData : public FragmentData {};

class FRaycast : public QOpenGLWidget, public Fragment {
  Q_OBJECT

  public:
    FRaycast(Fragment& parent, FragmentData& parentData);

    virtual void rebuild(const FragmentSpec& spec) override;
    virtual void cleanUp() override;

  public slots:
    void tick();

  protected:
    void paintEvent(QPaintEvent* event) override;
    void keyPressEvent(QKeyEvent* event) override;
    void keyReleaseEvent(QKeyEvent* event) override;

  private:
    FRaycastData m_data;

    std::unique_ptr<QTimer> m_timer;
    std::unique_ptr<Scene> m_scene;
    std::map<int, bool> m_keyStates;
};


#endif
