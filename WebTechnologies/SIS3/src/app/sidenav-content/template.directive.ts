import { Directive, Type, ComponentRef, ComponentFactoryResolver, ViewRef, ViewContainerRef } from '@angular/core';

@Directive({
  selector: '[appTemplate]',
  exportAs: 'templateDirective'
})
export class TemplateDirective {

  constructor(private cfr: ComponentFactoryResolver, private viewRef: ViewContainerRef) { }

  public setComponent<TComponent>(component: Type<TComponent>): ComponentRef<TComponent> {
    const factory = this.cfr.resolveComponentFactory<TComponent>(component);
    this.viewRef.clear();
    const componentRef = this.viewRef.createComponent(factory);
    return componentRef;
  }
  
  public addComponent<TComponent>(component: Type<TComponent>): ComponentRef<TComponent> {
    const factory = this.cfr.resolveComponentFactory<TComponent>(component);
    const componentRef = this.viewRef.createComponent(factory);
    return componentRef;
  }

}