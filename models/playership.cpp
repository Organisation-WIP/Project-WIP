#include "playership.h"
#include "../frameworkExtension/animationbone.h"

const QString PlayerShip::BONE_BASE = "base";
const QString PlayerShip::BONE_WSL = "wsl";
const QString PlayerShip::BONE_WSR = "wsr";
const QString PlayerShip::BONE_WBL = "wbl";
const QString PlayerShip::BONE_WBR = "wbr";
const QString PlayerShip::BONE_WINDSHIELD = "windshield";
/*landed = new Animation();
start = new Animation();
PlayerShip::idle = new Animation();*/
bool PlayerShip::initialized = false;

PlayerShip::PlayerShip()
{
    QString path(SRCDIR);

    m_mesh_base = new TriangleMesh(path+"/Object/playerspaceship_base.obj");
    m_mesh_wBL = new TriangleMesh(path+"/Object/playerspaceship_wingBig_left.obj");
    m_mesh_wBR = new TriangleMesh(path+"/Object/playerspaceship_wingBig_right.obj");
    m_mesh_wSL = new TriangleMesh(path+"/Object/playerspaceship_wingSmall_left.obj");
    m_mesh_wSR = new TriangleMesh(path+"/Object/playerspaceship_wingSmall_right.obj");
    m_mesh_windshield = new TriangleMesh(path+"/Object/playerspaceship_windshield.obj");

    m_draw_base = new Drawable(m_mesh_base);
    m_draw_wBL = new Drawable(m_mesh_wBL);
    m_draw_wBR = new Drawable(m_mesh_wBR);
    m_draw_wSL = new Drawable(m_mesh_wSL);
    m_draw_wSR = new Drawable(m_mesh_wSR);
    m_draw_windshield= new Drawable(m_mesh_windshield);

    m_bone_base = new Bone(BONE_BASE,this);
    m_bone_wBL = new Bone(BONE_WBL,this);
    m_bone_wBR = new Bone(BONE_WBR,this);
    m_bone_wSL = new Bone(BONE_WSL,this);
    m_bone_wSR = new Bone(BONE_WSR,this);
    m_bone_windshield = new Bone(BONE_WINDSHIELD,this);

    /*--------------------------------*/

    m_bone_windshield->translate(0, 1.15806, -1.04364);
    m_bone_wSL->translate(3.22861, -1.16905, -3.32254);
    m_bone_wSR->translate(-3.22861, -1.16905, -3.32254);
    m_bone_wBL->translate(4.13471, 2.23739, 3.14145);
    m_bone_wBR->translate(-4.13471, 2.23739, 3.14145);

    /*--------------------------------*/

    m_bone_base->addChild(new Node(m_draw_base));

    m_bone_wBL->addChild(new Node(m_draw_wBL));
    m_bone_wSL->addChild(new Node(m_draw_wSL));
    m_bone_wSL->addChild(m_bone_wBL);
    m_bone_base->addChild(m_bone_wSL);

    m_bone_wBR->addChild(new Node(m_draw_wBR));
    m_bone_wSR->addChild(new Node(m_draw_wSR));
    m_bone_wSR->addChild(m_bone_wBR);
    m_bone_base->addChild(m_bone_wSR);

    m_bone_windshield->addChild(new Node(m_draw_windshield));
    m_bone_base->addChild(m_bone_windshield);

    this->addChild(m_bone_base);

    if(!initialized)
    {
        initAnimations();
        initialized = true;
    }
}
PlayerShip::~PlayerShip()
{
    delete m_bone_base;
    delete m_bone_wBL;
    delete m_bone_wBR;
    delete m_bone_wSL;
    delete m_bone_wSR;
    delete m_bone_windshield;

    delete m_draw_base;
    delete m_draw_wBL;
    delete m_draw_wBR;
    delete m_draw_wSL;
    delete m_draw_wSR;
    delete m_draw_windshield;

    delete m_bone_base;
    delete m_bone_wBL;
    delete m_bone_wBR;
    delete m_bone_wSL;
    delete m_bone_wSR;
    delete m_bone_windshield;
}

void PlayerShip::initAnimations()
{
    landed = new Animation();
    start = new Animation();
    idle = new Animation();

    /*--landed----------------------*/
    AnimationBone* bone = new AnimationBone(BONE_WINDSHIELD);
    Graph* graph = new Graph();
    graph->insertKeyframe(new Keyframe(0,1));
    bone->setGraph(AnimationBone::ROT_X, graph);
    graph = new Graph();
    graph->insertKeyframe(new Keyframe(0,-70));
    bone->setGraph(AnimationBone::ROT_S, graph);
    landed->addAnimationBone(bone);

    bone = new AnimationBone(BONE_WSL);
    graph = new Graph();
    graph->insertKeyframe(new Keyframe(0,1));
    bone->setGraph(AnimationBone::ROT_X, graph);
    graph = new Graph();
    graph->insertKeyframe(new Keyframe(0,-105));
    bone->setGraph(AnimationBone::ROT_S, graph);
    landed->addAnimationBone(bone);

    bone = new AnimationBone(BONE_WSR);
    graph = new Graph();
    graph->insertKeyframe(new Keyframe(0,1));
    bone->setGraph(AnimationBone::ROT_X, graph);
    graph = new Graph();
    graph->insertKeyframe(new Keyframe(0,-105));
    bone->setGraph(AnimationBone::ROT_S, graph);
    landed->addAnimationBone(bone);

    bone = new AnimationBone(BONE_WBL);
    graph = new Graph();
    graph->insertKeyframe(new Keyframe(0,1));
    bone->setGraph(AnimationBone::ROT_Z, graph);
    graph = new Graph();
    graph->insertKeyframe(new Keyframe(0,-25));
    bone->setGraph(AnimationBone::ROT_S, graph);
    landed->addAnimationBone(bone);

    bone = new AnimationBone(BONE_WBR);
    graph = new Graph();
    graph->insertKeyframe(new Keyframe(0,1));
    bone->setGraph(AnimationBone::ROT_Z, graph);
    graph = new Graph();
    graph->insertKeyframe(new Keyframe(0,25));
    bone->setGraph(AnimationBone::ROT_S, graph);
    landed->addAnimationBone(bone);


    /*--start----------------------*/
    bone = new AnimationBone(BONE_BASE);
    graph = new Graph();
    graph->insertKeyframe(new Keyframe(0,0,Interpolation::getSineInterpolation()));
    graph->insertKeyframe(new Keyframe(5,10,Interpolation::getSineInterpolation()));
    bone->setGraph(AnimationBone::TRANS_Y, graph);
    start->addAnimationBone(bone);

    bone = new AnimationBone(BONE_WINDSHIELD);
    graph = new Graph();
    graph->insertKeyframe(new Keyframe(0,1));
    bone->setGraph(AnimationBone::ROT_X, graph);
    graph = new Graph();
    graph->insertKeyframe(new Keyframe(0.6,-70));
    graph->insertKeyframe(new Keyframe(2,0,Interpolation::getSineInterpolation()));
    bone->setGraph(AnimationBone::ROT_S, graph);
    start->addAnimationBone(bone);

    bone = new AnimationBone(BONE_WSL);
    graph = new Graph();
    graph->insertKeyframe(new Keyframe(0,1));
    bone->setGraph(AnimationBone::ROT_X, graph);
    graph = new Graph();
    graph->insertKeyframe(new Keyframe(2,-105));
    graph->insertKeyframe(new Keyframe(4.5,0));
    bone->setGraph(AnimationBone::ROT_S, graph);
    start->addAnimationBone(bone);

    bone = new AnimationBone(BONE_WSR);
    graph = new Graph();
    graph->insertKeyframe(new Keyframe(0,1));
    bone->setGraph(AnimationBone::ROT_X, graph);
    graph = new Graph();
    graph->insertKeyframe(new Keyframe(2,-105));
    graph->insertKeyframe(new Keyframe(4.5,0));
    bone->setGraph(AnimationBone::ROT_S, graph);
    start->addAnimationBone(bone);

    bone = new AnimationBone(BONE_WBL);
    graph = new Graph();
    graph->insertKeyframe(new Keyframe(0,1));
    bone->setGraph(AnimationBone::ROT_Z, graph);
    graph = new Graph();
    graph->insertKeyframe(new Keyframe(3,-25));
    graph->insertKeyframe(new Keyframe(4.5,0));
    bone->setGraph(AnimationBone::ROT_S, graph);
    start->addAnimationBone(bone);

    bone = new AnimationBone(BONE_WBR);
    graph = new Graph();
    graph->insertKeyframe(new Keyframe(0,1));
    bone->setGraph(AnimationBone::ROT_Z, graph);
    graph = new Graph();
    graph->insertKeyframe(new Keyframe(3,25));
    graph->insertKeyframe(new Keyframe(4.5,0));
    bone->setGraph(AnimationBone::ROT_S, graph);
    start->addAnimationBone(bone);
}
