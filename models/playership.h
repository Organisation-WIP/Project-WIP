#ifndef PLAYERSHIP_H
#define PLAYERSHIP_H

#include "node.h"
#include "frameworkExtension/model.h"
#include "drawable.h"
#include "trianglemesh.h"
#include "../frameworkExtension/animation.h"


class PlayerShip : public Model
{
public:
    static const QString BONE_BASE,BONE_WSL,BONE_WSR,BONE_WBL,BONE_WBR,BONE_WINDSHIELD;
    Animation *landed,*start,*idle;

    PlayerShip();
    virtual ~PlayerShip();

    void initAnimations();

private:
    TriangleMesh* m_mesh_base,*m_mesh_wSL,*m_mesh_wSR,*m_mesh_wBL,*m_mesh_wBR,*m_mesh_windshield;
    Drawable* m_draw_base,*m_draw_wSL,*m_draw_wSR,*m_draw_wBL,*m_draw_wBR,*m_draw_windshield;
    Bone* m_bone_base,*m_bone_wSL,*m_bone_wSR,*m_bone_wBL,*m_bone_wBR,*m_bone_windshield;

    static bool initialized;
};

#endif // PLAYERSHIP_H
