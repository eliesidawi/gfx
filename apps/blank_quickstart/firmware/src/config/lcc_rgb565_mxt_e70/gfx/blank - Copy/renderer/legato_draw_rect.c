#include "gfx/blank/renderer/legato_renderer.h"

#include "gfx/blank/common/legato_math.h"
#include "gfx/blank/datastructure/legato_rectarray.h"

leResult leRenderer_RectLine(const leRect* rect,
                             leColor clr,
                             uint32_t a)
{
    leRenderer_HorzLine(rect->x,
                        rect->y,
                        rect->width,
                        clr,
                        a);
                        
    leRenderer_HorzLine(rect->x,
                        rect->y + rect->height - 1,
                        rect->width,
                        clr,
                        a);
                        
    leRenderer_VertLine(rect->x,
                        rect->y,
                        rect->height,
                        clr,
                        a);
                        
    leRenderer_VertLine(rect->x + rect->width - 1,
                        rect->y,
                        rect->height,
                        clr,
                        a);
    
    return LE_SUCCESS;
}

leResult leRenderer_RectFill(const leRect* rect,
                             leColor clr,
                             uint32_t a)
{
    leRect clipRect;

    if(leRenderer_CullDrawRect(rect) == LE_TRUE)
        return LE_FAILURE;
        
    leRenderer_ClipDrawRect(rect, &clipRect);
    
    a = leClampi(0, 255, a);

    leRenderer_FillArea(clipRect.x,
                        clipRect.y,
                        clipRect.width,
                        clipRect.height,
                        clr,
                        a);

    return LE_SUCCESS;
}

leResult leRenderer_HorzGradientRect(const leRect* rect,
                                     leColor clr1,
                                     leColor clr2,
                                     uint32_t a)
{
    lePoint drawPoint;
    leColor clr;
    int32_t val;
    uint32_t percent;
    
    // calculate minimums
    drawPoint.y = rect->y;
    
    for(drawPoint.x = rect->x; drawPoint.x < rect->x + rect->width; drawPoint.x++)
    {
        val = drawPoint.x - rect->x;
        
        percent = lePercentWholeRounded(val, rect->width);
        
        clr = leColorLerp(clr1, clr2, percent, LE_GLOBAL_COLOR_MODE);
                                 
        leRenderer_VertLine(drawPoint.x,
                            drawPoint.y,
                            rect->y + rect->height,
                            clr,
                            a);
    }
    
    return LE_SUCCESS;
}
                                          
leResult leRenderer_VertGradientRect(const leRect* rect,
                                     leColor clr1,
                                     leColor clr2,
                                     uint32_t a)
{
    lePoint drawPoint;
    leColor clr;
    int32_t val;
    uint32_t percent;
    
    // calculate minimums
    drawPoint.x = rect->x; 
    
    for(drawPoint.y = rect->y; drawPoint.y < rect->y + rect->height; drawPoint.y++)
    {
        val = drawPoint.y - rect->y;
        
        percent = lePercentWholeRounded(val, rect->height);
        
        clr = leColorLerp(clr1, clr2, percent, LE_GLOBAL_COLOR_MODE);
                                 
        leRenderer_HorzLine(drawPoint.x,
                            drawPoint.y,
                            rect->x + rect->width,
                            clr,
                            a);
    }
    
    return LE_SUCCESS;
}