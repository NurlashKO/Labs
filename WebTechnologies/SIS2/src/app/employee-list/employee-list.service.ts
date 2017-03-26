import { Injectable } from '@angular/core';
import { Employee } from './employee-list.model'

export const EMPLOYEES: Employee[] = [
  {id: 1, name: "NurlashKO", description: "Good"},
  {id: 2, name: "IsKO", description: "Nice"},
  {id: 3, name: "MirzhanKO", description: "Very Good"},
  {id: 4, name: "SanzharKO", description: "The Best Good"},
];

@Injectable()
export class EmployeeListService {

  constructor() { }

}
