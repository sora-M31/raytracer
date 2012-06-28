#ifndef _MATERIAL_H_
#define _MATERIAL_H_

#include "texture.h"
//#include "vector2D.h"

namespace rayTracer
{
class Shape;
class Vector;
class Vector2D;

class Material
{
public:
	//static const Material kAir;

	Material ();
	Material ( float _kd, float _ks, const Shape* _pShape = 0, float _index = 0, float _attenuation = 0.1 );
	Material ( const Material& _material );
	Material& operator = ( const Material& _other );

	//Color GetColor( const Vector& _position ) const;
	Color GetColor( const Vector2D& _texCoord ) const;

	float Index () const { return m_index; };
	float kDiffuse () const { return m_kd; }
	float kSpecular () const { return m_ks; }
	float Attenuation () const { return m_attenuation; }
	const Texture* GetTexture () const { return m_pTexture; }
	void SetTexture ( const Texture* _texture ) { m_pTexture = _texture; }

private:
	float m_kd;
	float m_ks;
	const Shape* m_pShape;
	//refraction index
	float m_index;
	///\coefficient for attenuation
	float m_attenuation;
	const Texture* m_pTexture;
};
}//end of namespace
#endif
