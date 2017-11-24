#pragma once

#include <QWidget>

#include <QOpenGLShaderProgram>
#include <QOpenGLFunctions>
#include <QOpenGLVertexArrayObject>
#include <QTimer>
#include <QOpenGLFramebufferObject>

#include "node.h"
#include "camera.h"

#include "material/phong.h"
#include "material/planet.h"
#include "material/vectors.h"
#include "material/wireframe.h"

#include "navigator/rotate_y.h"
#include "navigator/position_navigator.h"

#include <memory> // std::unique_ptr
#include <map>    // std::map
#include <chrono> // clock, time calculations

/*
 * OpenGL-based scene. Required objects are created in the constructor,
 * and the scene is rendered using render().
 *
 * Also, the scene derives from QObject so it can use Qt's
 * signal and slot mechanism to connect to the app's UI.
 *
 * Do not call render() directly, use update() instead.
 *
 */

class Scene : public QObject, protected QOpenGLFunctions
{
    Q_OBJECT

public:
    explicit Scene(QWidget* parent, QOpenGLContext *context);

    QMatrix4x4& worldTransform() { return nodes_["World"]->transformation; }

signals:

    void displayBufferContents(unsigned int id, QString label, const QImage& img);

public slots:

    // change model according to combo box in UI
    void setSceneNode(QString txt);

    // change shader program
    void setShader(QString txt);

    // change background color
    void setBackgroundColor(QVector3D rgb) {
        bgcolor_ = rgb; update();
    }

    // methods to change material parameters
    void toggleAnimation(bool flag);
    void setLightIntensity(size_t, float v) {
        planetMaterial_->lights[0].intensity = v; update();
    }
    void setBlendExponent(float v) {
        planetMaterial_->planet.night_blend_exp= v*10.0; update();
    }
    void setNightScale(float v) {
        planetMaterial_->planet.night_scale = v*5.0; update();
    }
    void toggleBumpMapping(bool flag) {
        planetMaterial_->bump.use = flag; update();
    }
    void setBumpMapScale(float v) {
        planetMaterial_->bump.scale = v*3; update();
    }
    void toggleDisplacementMapping(bool flag) {
        planetMaterial_->displacement.use = flag; update();
    }
    void setDisplacementMapScale(float v) {
        planetMaterial_->displacement.scale = v/5.0; update();
    }
    void toggleWireframe(bool flag)  {
        showWireframe = flag; update();
    }
    void visualizeVectors(int which) {
        // this mapping from some numbers to 0, 1, 2, 3 was determined heuristically :-)
        // qDebug() << "which: " << -2-which;
        vectorsMaterial_->vectorToShow = -2-which; update();
    }
    void setVectorScale(float v) {
        vectorsMaterial_->scale = v/10.0; update();
    }

    // key/mouse events from UI system, pass on to navigators or such
    void keyPressEvent(QKeyEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent *event);

    /*
     *  perform OpenGL rendering of the entire scene.
     *  Don't call this yourself (!) - use update() instead.
     *
     */
    void draw();

    // anyone can trigger a redraw of the widget through this method
    void update();

    // adjust camera / viewport / ... if drawing surface changes
    void updateViewport(size_t width, size_t height);

protected:

    // draw the actual scene
    void draw_scene_();

    // used to replace material in all meshes before drawing
    void replaceMaterialAndDrawScene(const Camera &camera, std::shared_ptr<Material> mat);

    // parent widget
    QWidget* parent_;

    // periodically update the scene for animations
    QTimer timer_;

    // track time for animations
    std::chrono::high_resolution_clock clock_;
    std::chrono::time_point<std::chrono::high_resolution_clock> firstDrawTime_;
    std::chrono::time_point<std::chrono::high_resolution_clock> lastDrawTime_;

    // rotation
    double angle = 0.0;
    bool rotationOn = true;

    // bg color
    QVector3D bgcolor_ = QVector3D(0.4f,0.4f,0.4f);

    // different materials to be demonstrated
    std::shared_ptr<PlanetMaterial> planetMaterial_, material_;
    std::shared_ptr<WireframeMaterial> wireframeMaterial_;
    std::shared_ptr<VectorsMaterial> vectorsMaterial_;

    // additional debugging information to show
    bool drawUsingPlanetShader = true;
    bool showWireframe  = false;

    // mesh(es) to be used / shared
    std::map<QString, std::shared_ptr<Mesh>> meshes_;

    // nodes to be used
    std::map<QString, std::shared_ptr<Node>> nodes_;

    // light nodes for any number of lights
    std::vector<std::shared_ptr<Node>> lightNodes_;

    // navigation
    std::unique_ptr<RotateY> cameraNavigator_;
    std::unique_ptr<PositionNavigator> lightNavigator_;

    // helper for creating programs from shader files
    std::shared_ptr<QOpenGLShaderProgram> createProgram(const std::string& vertex,
                                                        const std::string& fragment,
                                                        const std::string& geom = "");

    // helper for creating a node scaled to size 1
    std::shared_ptr<Node> createNode(std::shared_ptr<Mesh> mesh, bool scale_to_1 = true);

    // helpers to construct the objects and to build the hierarchical scene
    void makeNodes();
    void makeScene();

};

