#ifndef _RAYTRACER_H_
#define _RAYTRACER_H_
#include <ostream>
#include "intersection.h"
#include "ray.h"
#include "scene.h"
#include "color.h"
namespace rayTracer
{
class RayTracer
{
public:
    RayTracer( Scene* _pScene =0 );
    ~RayTracer();
	void SetScene( Scene* _pScene ) { m_pScene = _pScene; }
	//void SetScene( const Scene* _pScene ) { m_pScene = _pScene; }
    Intersection IntersectScene ( const Ray& _ray );
    Color Trace( const Ray& _ray, int _depth, std::ofstream& o_output );
    void CastRay( uint32_t _frame );
	Color Diffuse( const Intersection& _intersection, const Vector& _lightDir, float _attenuation );
	Color Specular( const Intersection& _intersection, const Vector& _viewingDir, const Vector& _lightDir, float _attenuation );

private:
    //Scene m_scene;
	const Scene* m_pScene;
    bool m_antialias;
    bool m_depthOfField;
    bool m_softShadow;
    bool m_differentGeo;
	//std::list<Vector> lenSample;
};//end of class
}//end of namespace
#endif //end of define
