import { Component, ViewChild, OnInit, Directive, Type, ComponentRef, ComponentFactoryResolver, ViewRef, ViewContainerRef } from '@angular/core';
import { TemplateDirective } from '../../sidenav-content/template.directive';
import { FkNewsCardComponent } from '../fk-news-card/fk-news-card.component';

@Component({
  selector: 'app-fk-sidenav',
  templateUrl: './fk-sidenav.component.html',
  styleUrls: ['./fk-sidenav.component.css']
})
export class FkSidenavComponent implements OnInit {

  @ViewChild(TemplateDirective) private template: TemplateDirective;
  constructor(private cfr: ComponentFactoryResolver, private viewRef: ViewContainerRef) { }

  public setNewsList() {
    this.template.setComponent(FkNewsCardComponent);
  }
  ngOnInit() {
  }

}
