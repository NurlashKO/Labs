import { Http, Response } from '@angular/http';
import { Injectable } from '@angular/core';

import { Observable } from 'rxjs/Observable';
import 'rxjs/add/operator/catch';
import 'rxjs/add/operator/map';

import { Post } from '../models/post';

const POSTS: Post[] = [
  {id: 1, title: "POST 1", short_description: "MY DESCRIPTION1", content: "MY CONTENT", publish_date: "12/12/12", author: "NurlashKO"},
  {id: 1, title: "POST 2", short_description: "MY DESCRIPTION1", content: "MY CONTENT", publish_date: "12/12/12", author: "NurlashKO"},
  {id: 1, title: "POST 3", short_description: "MY DESCRIPTION1", content: "MY CONTENT", publish_date: "12/12/12", author: "NurlashKO"},
  {id: 1, title: "POST 4", short_description: "MY DESCRIPTION1", content: "MY CONTENT", publish_date: "12/12/12", author: "NurlashKO"},
  {id: 1, title: "POST 5", short_description: "MY DESCRIPTION1", content: "MY CONTENT", publish_date: "12/12/12", author: "NurlashKO"}, 
];

@Injectable()
export class PostService {
  private PostsURL = "http://localhost:8000/posts/";

  constructor(private http: Http) {};

  dummyGetPosts(): Post[] {
    return POSTS;
  }

  getPosts(): Observable<Post[]> {
    return this.http.get(this.PostsURL)
                    .map(this.extractData)
                    .catch(this.handleError);
  }

  getPostById(id: number): Observable<Post> {
    return this.http.get(this.PostsURL + id.toString()+"/")
                    .map(this.extractData)
                    .catch(this.handleError);
  }

  private extractData(res: Response) {
    let body = res.json();
    return body || [ ];
  }

  private handleError (error: Response | any) {
    // In a real world app, you might use a remote logging infrastructure
    let errMsg: string;
    if (error instanceof Response) {
      const body = error.json() || '';
      const err = body.error || JSON.stringify(body);
      errMsg = `${error.status} - ${error.statusText || ''} ${err}`;
    } else {
      errMsg = error.message ? error.message : error.toString();
    }
    console.error(errMsg);
    return Observable.throw(errMsg);
  }
}

