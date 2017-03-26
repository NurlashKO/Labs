import { Component, OnInit } from '@angular/core';
import { Employee } from './employee-list.model';
import { EMPLOYEES } from './employee-list.service';


@Component({
  selector: 'app-employee-list',
  templateUrl: './employee-list.component.html',
  styleUrls: ['./employee-list.component.scss']
})
export class EmployeeListComponent implements OnInit {

  public employees = EMPLOYEES;
  public description: string = "";

  constructor() { }

  ngOnInit() {
  }

  public changeDesc(employee) {
    console.log("LOL");
    this.description = employee.description;
  }
}
