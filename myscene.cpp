#include "opengl.h"
#include "window.h"
#include "screenrenderer.h"
#include "scenemanager.h"
#include "transformation.h"
#include "keyboardtransformation.h"
#include "controllablecamera.h"
#include "color.h"
#include "models/tower.h"
#include "models/playership.h"
#include "frameworkExtension/animation.h"
#include "frameworkExtension/animationbone.h"
#include "ui_dockwidget.h"

Node *initScene1();

void SceneManager::initScenes()
{
    Ui_FPSWidget *lDock;
    QDockWidget *lDockWidget = new QDockWidget(QString("FPS"), SceneManager::getMainWindow());

    ControllableCamera *cam = new ControllableCamera();
    RenderingContext *myContext=new RenderingContext(cam);
    unsigned int myContextNr = SceneManager::instance()->addContext(myContext);
    unsigned int myScene = SceneManager::instance()->addScene(initScene1());
    ScreenRenderer *myRenderer = new ScreenRenderer(myContextNr, myScene);

    //Vorsicht: Die Szene muss initialisiert sein, bevor das Fenster verändert wird (Fullscreen)
    SceneManager::instance()->setActiveScene(myScene);
    SceneManager::instance()->setActiveContext(myContextNr);
//    SceneManager::instance()->setFullScreen();

    lDock = new Ui_FPSWidget();
    lDock->setupUi(lDockWidget);
    lDockWidget->resize(200,100);
    SceneManager::getMainWindow()->addDockWidget(Qt::RightDockWidgetArea, lDockWidget);
    lDockWidget->show();
    QObject::connect(Window::getInstance(), SIGNAL(sigFPS(int)), lDock->lcdNumber, SLOT(display(int)));
}

Node *initScene1()
{
    KeyboardTransformation* schieber = new KeyboardTransformation();
    KeyboardTransformation* rotierer = new KeyboardTransformation();
    rotierer->setRotKeys(KeyboardTransformation::NoKey,KeyboardTransformation::NoKey,
                        'r', 'R',
                        KeyboardTransformation::NoKey, KeyboardTransformation::NoKey);
    rotierer->setRotspeed(1.f);
    schieber->setTransKeys('l','j',
                          'I','K',
                          'i','k');
    schieber->setTransspeed(0.5f);

    Tower* aTower = new Tower(5.0f);
    PlayerShip* player = new PlayerShip();

    Node* rotiererNode = new Node(rotierer);
    rotiererNode->addChild(aTower);
    rotiererNode->addChild(player);

    Node* schieberNode = new Node(schieber);
    schieberNode->addChild(rotiererNode);

    //Animation--------------------------
    /*Animation* anim = new Animation();
    AnimationBone* top = new AnimationBone("top");
    Graph* gr = new Graph();
    gr->insertKeyframe(new Keyframe(0,0, Interpolation::getSineInterpolation()));
    gr->insertKeyframe(new Keyframe(5000,359, Interpolation::getSineInterpolation()));
    Graph* axis = new Graph();
    axis->insertKeyframe(new Keyframe(0,1));
    top->setGraph(BONE_ROT_S, gr);
    top->setGraph(BONE_ROT_Y, axis);
    anim->addAnimationBone(top);
    anim->start(aTower,true,true);*/

    player->landed->start(player);
    player->start->start(player, true, true);

    return schieberNode;
}
