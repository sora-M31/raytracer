#include "material.h"
#include "shape.h"
namespace rayTracer
{
//Material::kAir(foobar);

//---------------------------------------------------------------------------------------
Material::Material()
: m_kd ( 0 ),
  m_ks ( 0 ),
  m_km ( 0 ),
  m_kg ( 0 ),
  m_kr ( 0 ),
  m_index ( 0 ),
  m_attenuation ( 0.1 ),
  m_color( Color(1,1,1,1) ),
  m_pTexture ( 0 )
{}
//---------------------------------------------------------------------------------------
Material::Material ( float _kd, float _ks, float _km, float _kg, float _kr, float _index, float _attenuation, const Color& _color )
: m_kd ( _kd ),
  m_ks ( _ks ),
  m_km ( _km ),
  m_kg ( _kg ),
  m_kr ( _kr ),
  m_index ( _index ),
  m_attenuation ( _attenuation ),
  m_color ( _color ),
  m_pTexture ( 0 )
{}
//---------------------------------------------------------------------------------------
Material::Material ( const Material& _material )
: m_kd ( _material.m_kd ),
  m_ks ( _material.m_ks ),
  m_km ( _material.m_km ),
  m_kg ( _material.m_kg ),
  m_kr ( _material.m_kr ),
  m_index ( _material.m_index ),
  m_attenuation ( _material.m_attenuation ),
  m_color ( _material.m_color ),
  m_pTexture ( _material.m_pTexture )
{}
//---------------------------------------------------------------------------------------
Material& Material::operator = ( const Material& _other )
{
    m_kd = _other.m_kd;
    m_ks = _other.m_ks;
    m_km = _other.m_km;
    m_kg = _other.m_kg;
    m_kr = _other.m_kr;
    m_index = _other.m_index;
    m_attenuation = _other.m_attenuation;
    m_pTexture = _other.m_pTexture;
    m_color = _other.m_color;
    return *this;
}
//---------------------------------------------------------------------------------------
Color Material::GetColor( const Vector2D& _texCoord ) const
{
    if ( m_pTexture != 0 )
        return m_pTexture->GetColorBilinear( _texCoord );
    else
        return m_color;
}
//---------------------------------------------------------------------------------------
void Material::SetColor( const Color& _color )
{
    m_color = _color;
}
#if 0
Color Material::GetColor( const Vector& _position ) const
{
    float u(0);
    float v(0);
    assert ( m_pShape != 0 );
    m_pShape->ToUVSpace ( _position, u, v );
    Color color ( 1,1,1,1 );
    if ( m_pTexture != 0 )
        color = m_pTexture->GetColorBilinear( u, v );
    return color;
}
#endif
}//end of namespace
