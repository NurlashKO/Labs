import { NgModule } from '@angular/core';
import { CommonModule } from '@angular/common';

import { FkNewsCardComponent } from '../components/fk-news-card/fk-news-card.component';
import { TemplateDirective } from './template.directive';

@NgModule({
  imports: [
    CommonModule
    //FkNewsCardComponent
  ],
  declarations: [
    TemplateDirective
  ],
  entryComponents: [
    //FkNewsCardComponent,
  ],
  exports: [
    //FkNewsCardComponent,
    TemplateDirective
  ]
})
export class SideNavContentModule { }