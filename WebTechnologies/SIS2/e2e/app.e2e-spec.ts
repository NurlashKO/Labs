import { SIS2Page } from './app.po';

describe('sis2 App', () => {
  let page: SIS2Page;

  beforeEach(() => {
    page = new SIS2Page();
  });

  it('should display message saying app works', () => {
    page.navigateTo();
    expect(page.getParagraphText()).toEqual('app works!');
  });
});
