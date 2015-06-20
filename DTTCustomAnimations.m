//
//  DTTCustomAnimations.m
//  Animation
//
//  Created by Shaurya on 20/06/15.
//  Copyright (c) 2015 DigitalThinkrz. All rights reserved.
//

#import "DTTCustomAnimations.h"
#import <QuartzCore/QuartzCore.h>

@implementation DTTCustomAnimations
+ (void)defaultCustomizedAnimationForView:(UIView *)animateView
                        fromStartingValue:(id)startValue
                            toEndingValue:(id)endValue
              withMediaTimingFunctionName:(NSString *)name
                      inAnimationDuration:(CFTimeInterval)duration
                               forKeyPath:(NSString *)keyPath
                   withAutoreverseAbility:(BOOL)isAutoreverses
                     andTotalRepeatCounts:(float)repeatCount
{
    if (!animateView || keyPath) return;
    
    CABasicAnimation *customAnimation   = [CABasicAnimation animationWithKeyPath:keyPath];
    customAnimation.fromValue           = startValue;
    customAnimation.toValue             = endValue;
    customAnimation.fillMode            = kCAFillModeBoth;
    customAnimation.duration            = duration;
    customAnimation.repeatCount         = repeatCount;
    customAnimation.autoreverses        = isAutoreverses;
    customAnimation.timingFunction      = [CAMediaTimingFunction functionWithName:name];
    customAnimation.removedOnCompletion = NO;
    [animateView.layer addAnimation:customAnimation forKey:nil];
    customAnimation = nil;
}

+ (void)setAnchorPoint:(CGPoint)anchorPoint forAnyView:(UIView *)view
{
    if (!view) return;
    CGPoint newPoint = CGPointMake(view.bounds.size.width * anchorPoint.x, view.bounds.size.height * anchorPoint.y);
    CGPoint oldPoint = CGPointMake(view.bounds.size.width * view.layer.anchorPoint.x, view.bounds.size.height * view.layer.anchorPoint.y);
    newPoint = CGPointApplyAffineTransform(newPoint, view.transform);
    oldPoint = CGPointApplyAffineTransform(oldPoint, view.transform);
    
    CGPoint position        = view.layer.position;
    position.x              -= oldPoint.x;
    position.x              += newPoint.x;
    position.y              -= oldPoint.y;
    position.y              += newPoint.y;
    view.layer.position     = position;
    view.layer.anchorPoint  = anchorPoint;
}
@end
