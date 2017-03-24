import { Component, OnInit } from '@angular/core';
import { Task } from './../../models/task';
import { ProjectService } from '../../services/project.service';

@Component({
  selector: 'app-task-list',
  templateUrl: './task-list.component.html',
  styleUrls: ['./task-list.component.scss'],
  providers: [ProjectService]
})
export class TaskListComponent implements OnInit {

  public tasks: Task[];
  
  constructor(private projectService: ProjectService) {

    projectService.getProjects().subscribe( 
      (tasks) => {
        this.tasks = tasks['value'] as Task[];
        console.log(tasks['value']);
    }, (err) => {
        console.log(err);
      }
    );
    this.tasks = [
     {title: "ez task", description: "Super ez task for me", isDone: true},
      {title: "hard task", description: "Super hard task for me", isDone: false}
    ];
  }

  ngOnInit() {
  }

}
